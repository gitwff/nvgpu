/*
 * Copyright (c) 2018-2019, NVIDIA CORPORATION.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <nvgpu/pmuif/gpmuif_cmn.h>
#include <nvgpu/sec2/lsfm.h>
#include <nvgpu/sec2/msg.h>
#include <nvgpu/gk20a.h>
#include <nvgpu/sec2/cmd.h>

/* Add code below to handle SEC2 RTOS commands */
/* LSF's bootstrap command */
static void sec2_handle_lsfm_boot_acr_msg(struct gk20a *g,
	struct nv_flcn_msg_sec2 *msg,
	void *param, u32 status)
{
	bool *command_ack = param;

	nvgpu_log_fn(g, " ");

	nvgpu_sec2_dbg(g, "reply NV_SEC2_ACR_CMD_ID_BOOTSTRAP_FALCON");

	nvgpu_sec2_dbg(g, "flcn %d: error code = %x",
		msg->msg.acr.msg_flcn.falcon_id,
		msg->msg.acr.msg_flcn.error_code);

	*command_ack = true;
}

static void sec2_load_ls_falcons(struct gk20a *g, struct nvgpu_sec2 *sec2,
	u32 falcon_id, u32 flags)
{
	struct nv_flcn_cmd_sec2 cmd;
	bool command_ack;
	int err = 0;
	size_t tmp_size;

	nvgpu_log_fn(g, " ");

	/* send message to load falcon */
	(void) memset(&cmd, 0, sizeof(struct nv_flcn_cmd_sec2));
	cmd.hdr.unit_id = NV_SEC2_UNIT_ACR;
	tmp_size = PMU_CMD_HDR_SIZE +
		sizeof(struct nv_sec2_acr_cmd_bootstrap_falcon);
	nvgpu_assert(tmp_size <= U64(U8_MAX));
	cmd.hdr.size = U8(tmp_size);

	cmd.cmd.acr.bootstrap_falcon.cmd_type =
		NV_SEC2_ACR_CMD_ID_BOOTSTRAP_FALCON;
	cmd.cmd.acr.bootstrap_falcon.flags = flags;
	cmd.cmd.acr.bootstrap_falcon.falcon_id = falcon_id;

	nvgpu_sec2_dbg(g, "NV_SEC2_ACR_CMD_ID_BOOTSTRAP_FALCON : %x",
		falcon_id);

	command_ack = false;
	err = nvgpu_sec2_cmd_post(g, &cmd, PMU_COMMAND_QUEUE_HPQ,
		sec2_handle_lsfm_boot_acr_msg, &command_ack, U32_MAX);
	if (err != 0) {
		nvgpu_err(g, "command post failed");
	}

	err = nvgpu_sec2_wait_message_cond(sec2, nvgpu_get_poll_timeout(g),
		&command_ack, U8(true));
	if (err != 0) {
		nvgpu_err(g, "command ack receive failed");
	}
}

int nvgpu_sec2_bootstrap_ls_falcons(struct gk20a *g, struct nvgpu_sec2 *sec2,
	u32 falcon_id)
{
	int err = 0;

	nvgpu_log_fn(g, " ");

	nvgpu_sec2_dbg(g, "Check SEC2 RTOS is ready else wait");
	err = nvgpu_sec2_wait_message_cond(&g->sec2, nvgpu_get_poll_timeout(g),
			&g->sec2.sec2_ready, U8(true));
	if (err != 0) {
		nvgpu_err(g, "SEC2 RTOS not ready yet, failed to bootstrap flcn %d",
			falcon_id);
		goto exit;
	}

	nvgpu_sec2_dbg(g, "LS flcn %d bootstrap, blocked call", falcon_id);
	sec2_load_ls_falcons(g, sec2, falcon_id,
		NV_SEC2_ACR_CMD_BOOTSTRAP_FALCON_FLAGS_RESET_YES);

exit:
	nvgpu_sec2_dbg(g, "Done, err-%x", err);
	return err;
}
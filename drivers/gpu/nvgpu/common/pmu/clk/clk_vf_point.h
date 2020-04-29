/*
 * general clock structures & definitions
 *
 * Copyright (c) 2020, NVIDIA CORPORATION.  All rights reserved.
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

#ifndef NVGPU_CLK_VF_POINT_H
#define NVGPU_CLK_VF_POINT_H

struct nv_pmu_rpc_clk_domain_35_prog_freq_to_volt {
	/*[IN/OUT] Must be first field in RPC structure */
	struct nv_pmu_rpc_header hdr;
	u8 clk_domain_idx;
	u8 volt_rail_idx;
	u8 voltage_type;
	struct ctrl_clk_vf_input input;
	struct ctrl_clk_vf_output output;
	u32 scratch[1];
};

int clk_vf_point_init_pmupstate(struct gk20a *g);
void clk_vf_point_free_pmupstate(struct gk20a *g);
int clk_vf_point_sw_setup(struct gk20a *g);
int clk_vf_point_pmu_setup(struct gk20a *g);

#endif /* NVGPU_CLK_VF_POINT_H */

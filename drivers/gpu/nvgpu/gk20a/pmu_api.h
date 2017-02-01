/*
 * Copyright (c) 2011-2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#ifndef __PMU_API_H__
#define __PMU_API_H__

#include <nvgpu/flcnif_cmn.h>
#include "pmuif/gpmuif_pg_rppg.h"

/* ACR Commands/Message structures */

enum {
	PMU_ACR_CMD_ID_INIT_WPR_REGION = 0x0,
	PMU_ACR_CMD_ID_BOOTSTRAP_FALCON,
	PMU_ACR_CMD_ID_RESERVED,
	PMU_ACR_CMD_ID_BOOTSTRAP_MULTIPLE_FALCONS,
};

/*
 * Initializes the WPR region details
 */
struct pmu_acr_cmd_init_wpr_details {
	u8  cmd_type;
	u32 regionid;
	u32 wproffset;

};

/*
 * falcon ID to bootstrap
 */
struct pmu_acr_cmd_bootstrap_falcon {
	u8 cmd_type;
	u32 flags;
	u32 falconid;
};

/*
 * falcon ID to bootstrap
 */
struct pmu_acr_cmd_bootstrap_multiple_falcons {
	u8 cmd_type;
	u32 flags;
	u32 falconidmask;
	u32 usevamask;
	struct falc_u64 wprvirtualbase;
};

#define PMU_ACR_CMD_BOOTSTRAP_FALCON_FLAGS_RESET_NO  1
#define PMU_ACR_CMD_BOOTSTRAP_FALCON_FLAGS_RESET_YES 0


struct pmu_acr_cmd {
	union {
		u8 cmd_type;
		struct pmu_acr_cmd_bootstrap_falcon bootstrap_falcon;
		struct pmu_acr_cmd_init_wpr_details init_wpr;
		struct pmu_acr_cmd_bootstrap_multiple_falcons boot_falcons;
	};
};

/* acr messages */

/*
 * returns the WPR region init information
 */
#define PMU_ACR_MSG_ID_INIT_WPR_REGION   0

/*
 * Returns the Bootstrapped falcon ID to RM
 */
#define PMU_ACR_MSG_ID_BOOTSTRAP_FALCON  1

/*
 * Returns the WPR init status
 */
#define PMU_ACR_SUCCESS                  0
#define PMU_ACR_ERROR                    1

/*
 * PMU notifies about bootstrap status of falcon
 */
struct pmu_acr_msg_bootstrap_falcon {
	u8 msg_type;
	union {
		u32 errorcode;
		u32 falconid;
	};
};

struct pmu_acr_msg {
	union {
		u8 msg_type;
		struct pmu_acr_msg_bootstrap_falcon acrmsg;
	};
};
/*---------------------------------------------------------*/
/* FECS mem override command*/

#define PMU_LRF_TEX_LTC_DRAM_CMD_ID_EN_DIS   0

/*!
 * Enable/Disable FECS error feature
 */
struct pmu_cmd_lrf_tex_ltc_dram_en_dis {
	/*Command type must be first*/
	u8  cmd_type;
	/*unit bitmask*/
	u8  en_dis_mask;
};

struct pmu_lrf_tex_ltc_dram_cmd {
	union {
		u8 cmd_type;
		struct pmu_cmd_lrf_tex_ltc_dram_en_dis en_dis;
	};
};

/*  FECS mem override messages*/
#define PMU_LRF_TEX_LTC_DRAM_MSG_ID_EN_DIS    0

struct pmu_msg_lrf_tex_ltc_dram_en_dis {
	/*!
	 * Must be at start
	 */
	u8 msg_type;
	u8 en_fail_mask;
	u8 dis_fail_mask;
	u32 pmu_status;
};

struct pmu_lrf_tex_ltc_dram_msg {
	union {
		u8 msg_type;
		struct pmu_msg_lrf_tex_ltc_dram_en_dis en_dis;
	};
};

#endif /*__PMU_API_H__*/

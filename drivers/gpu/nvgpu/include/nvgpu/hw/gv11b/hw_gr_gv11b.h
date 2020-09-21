/*
 * Copyright (c) 2016-2020, NVIDIA CORPORATION.  All rights reserved.
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
/*
 * Function/Macro naming determines intended use:
 *
 *     <x>_r(void) : Returns the offset for register <x>.
 *
 *     <x>_o(void) : Returns the offset for element <x>.
 *
 *     <x>_w(void) : Returns the word offset for word (4 byte) element <x>.
 *
 *     <x>_<y>_s(void) : Returns size of field <y> of register <x> in bits.
 *
 *     <x>_<y>_f(u32 v) : Returns a value based on 'v' which has been shifted
 *         and masked to place it at field <y> of register <x>.  This value
 *         can be |'d with others to produce a full register value for
 *         register <x>.
 *
 *     <x>_<y>_m(void) : Returns a mask for field <y> of register <x>.  This
 *         value can be ~'d and then &'d to clear the value of field <y> for
 *         register <x>.
 *
 *     <x>_<y>_<z>_f(void) : Returns the constant value <z> after being shifted
 *         to place it at field <y> of register <x>.  This value can be |'d
 *         with others to produce a full register value for <x>.
 *
 *     <x>_<y>_v(u32 r) : Returns the value of field <y> from a full register
 *         <x> value 'r' after being shifted to place its LSB at bit 0.
 *         This value is suitable for direct comparison with other unshifted
 *         values appropriate for use in field <y> of register <x>.
 *
 *     <x>_<y>_<z>_v(void) : Returns the constant value for <z> defined for
 *         field <y> of register <x>.  This value is suitable for direct
 *         comparison with unshifted values appropriate for use in field <y>
 *         of register <x>.
 */
#ifndef NVGPU_HW_GR_GV11B_H
#define NVGPU_HW_GR_GV11B_H

#include <nvgpu/types.h>
#include <nvgpu/static_analysis.h>

#define gr_intr_r()                                                (0x00400100U)
#define gr_intr_notify_pending_f()                                        (0x1U)
#define gr_intr_notify_reset_f()                                          (0x1U)
#define gr_intr_semaphore_pending_f()                                     (0x2U)
#define gr_intr_semaphore_reset_f()                                       (0x2U)
#define gr_intr_illegal_method_pending_f()                               (0x10U)
#define gr_intr_illegal_method_reset_f()                                 (0x10U)
#define gr_intr_illegal_notify_pending_f()                               (0x40U)
#define gr_intr_illegal_notify_reset_f()                                 (0x40U)
#define gr_intr_firmware_method_f(v)                     ((U32(v) & 0x1U) << 8U)
#define gr_intr_firmware_method_pending_f()                             (0x100U)
#define gr_intr_firmware_method_reset_f()                               (0x100U)
#define gr_intr_illegal_class_pending_f()                                (0x20U)
#define gr_intr_illegal_class_reset_f()                                  (0x20U)
#define gr_intr_fecs_error_pending_f()                                (0x80000U)
#define gr_intr_fecs_error_reset_f()                                  (0x80000U)
#define gr_intr_class_error_pending_f()                              (0x100000U)
#define gr_intr_class_error_reset_f()                                (0x100000U)
#define gr_intr_exception_pending_f()                                (0x200000U)
#define gr_intr_exception_reset_f()                                  (0x200000U)
#define gr_fecs_intr_r()                                           (0x00400144U)
#define gr_class_error_r()                                         (0x00400110U)
#define gr_class_error_code_v(r)                         (((r) >> 0U) & 0xffffU)
#define gr_intr_nonstall_r()                                       (0x00400120U)
#define gr_intr_nonstall_trap_pending_f()                                 (0x2U)
#define gr_intr_en_r()                                             (0x0040013cU)
#define gr_exception_r()                                           (0x00400108U)
#define gr_exception_fe_m()                                    (U32(0x1U) << 0U)
#define gr_exception_gpc_m()                                  (U32(0x1U) << 24U)
#define gr_exception_memfmt_m()                                (U32(0x1U) << 1U)
#define gr_exception_ds_m()                                    (U32(0x1U) << 4U)
#define gr_exception_sked_m()                                  (U32(0x1U) << 8U)
#define gr_exception_pd_m()                                    (U32(0x1U) << 2U)
#define gr_exception_scc_m()                                   (U32(0x1U) << 3U)
#define gr_exception_ssync_m()                                 (U32(0x1U) << 5U)
#define gr_exception_mme_m()                                   (U32(0x1U) << 7U)
#define gr_exception1_r()                                          (0x00400118U)
#define gr_exception1_gpc_0_pending_f()                                   (0x1U)
#define gr_exception2_r()                                          (0x0040011cU)
#define gr_exception_en_r()                                        (0x00400138U)
#define gr_exception_en_fe_m()                                 (U32(0x1U) << 0U)
#define gr_exception_en_fe_enabled_f()                                    (0x1U)
#define gr_exception_en_gpc_m()                               (U32(0x1U) << 24U)
#define gr_exception_en_gpc_enabled_f()                             (0x1000000U)
#define gr_exception_en_memfmt_m()                             (U32(0x1U) << 1U)
#define gr_exception_en_memfmt_enabled_f()                                (0x2U)
#define gr_exception_en_ds_m()                                 (U32(0x1U) << 4U)
#define gr_exception_en_ds_enabled_f()                                   (0x10U)
#define gr_exception_en_pd_m()                                 (U32(0x1U) << 2U)
#define gr_exception_en_pd_enabled_f()                                    (0x4U)
#define gr_exception_en_scc_m()                                (U32(0x1U) << 3U)
#define gr_exception_en_scc_enabled_f()                                   (0x8U)
#define gr_exception_en_ssync_m()                              (U32(0x1U) << 5U)
#define gr_exception_en_ssync_enabled_f()                                (0x20U)
#define gr_exception_en_mme_m()                                (U32(0x1U) << 7U)
#define gr_exception_en_mme_enabled_f()                                  (0x80U)
#define gr_exception_en_sked_m()                               (U32(0x1U) << 8U)
#define gr_exception_en_sked_enabled_f()                                (0x100U)
#define gr_exception1_en_r()                                       (0x00400130U)
#define gr_exception2_en_r()                                       (0x00400134U)
#define gr_exception2_en_be_enabled_f()                                   (0x1U)
#define gr_gpfifo_ctl_r()                                          (0x00400500U)
#define gr_gpfifo_ctl_access_f(v)                        ((U32(v) & 0x1U) << 0U)
#define gr_gpfifo_ctl_access_disabled_f()                                 (0x0U)
#define gr_gpfifo_ctl_access_enabled_f()                                  (0x1U)
#define gr_gpfifo_ctl_semaphore_access_f(v)             ((U32(v) & 0x1U) << 16U)
#define gr_gpfifo_ctl_semaphore_access_enabled_v()                 (0x00000001U)
#define gr_gpfifo_ctl_semaphore_access_enabled_f()                    (0x10000U)
#define gr_gpfifo_status_r()                                       (0x00400504U)
#define gr_trapped_addr_r()                                        (0x00400704U)
#define gr_trapped_addr_mthd_v(r)                         (((r) >> 2U) & 0xfffU)
#define gr_trapped_addr_subch_v(r)                         (((r) >> 16U) & 0x7U)
#define gr_trapped_addr_mme_generated_v(r)                 (((r) >> 20U) & 0x1U)
#define gr_trapped_addr_datahigh_v(r)                      (((r) >> 24U) & 0x1U)
#define gr_trapped_addr_priv_v(r)                          (((r) >> 28U) & 0x1U)
#define gr_trapped_addr_status_v(r)                        (((r) >> 31U) & 0x1U)
#define gr_trapped_data_lo_r()                                     (0x00400708U)
#define gr_trapped_data_hi_r()                                     (0x0040070cU)
#define gr_trapped_data_mme_r()                                    (0x00400710U)
#define gr_trapped_data_mme_pc_v(r)                       (((r) >> 0U) & 0xfffU)
#define gr_status_r()                                              (0x00400700U)
#define gr_status_fe_method_upper_v(r)                      (((r) >> 1U) & 0x1U)
#define gr_status_fe_method_lower_v(r)                      (((r) >> 2U) & 0x1U)
#define gr_status_fe_method_lower_idle_v()                         (0x00000000U)
#define gr_status_fe_gi_v(r)                               (((r) >> 21U) & 0x1U)
#define gr_status_mask_r()                                         (0x00400610U)
#define gr_status_1_r()                                            (0x00400604U)
#define gr_status_2_r()                                            (0x00400608U)
#define gr_engine_status_r()                                       (0x0040060cU)
#define gr_engine_status_value_busy_f()                                   (0x1U)
#define gr_pri_be0_becs_be_exception_r()                           (0x00410204U)
#define gr_pri_be0_becs_be_exception_crop_m()                  (U32(0x1U) << 0U)
#define gr_pri_be0_becs_be_exception_zrop_m()                  (U32(0x1U) << 1U)
#define gr_pri_be0_becs_be_exception_en_r()                        (0x00410208U)
#define gr_pri_be0_becs_be_exception_en_crop_enabled_f()                  (0x1U)
#define gr_pri_be0_becs_be_exception_en_zrop_enabled_f()                  (0x2U)
#define gr_pri_gpc0_gpccs_gpc_exception_r()                        (0x00502c90U)
#define gr_pri_gpc0_gpccs_gpc_exception_en_r()                     (0x00502c94U)
#define gr_pri_gpc0_tpc0_tpccs_tpc_exception_r()                   (0x00504508U)
#define gr_pri_gpc0_tpc0_tpccs_tpc_exception_en_r()                (0x0050450cU)
#define gr_activity_0_r()                                          (0x00400380U)
#define gr_activity_1_r()                                          (0x00400384U)
#define gr_activity_2_r()                                          (0x00400388U)
#define gr_activity_4_r()                                          (0x00400390U)
#define gr_activity_4_gpc0_s()                                              (3U)
#define gr_activity_4_gpc0_f(v)                          ((U32(v) & 0x7U) << 0U)
#define gr_activity_4_gpc0_m()                                 (U32(0x7U) << 0U)
#define gr_activity_4_gpc0_v(r)                             (((r) >> 0U) & 0x7U)
#define gr_activity_4_gpc0_empty_v()                               (0x00000000U)
#define gr_activity_4_gpc0_preempted_v()                           (0x00000004U)
#define gr_pri_gpc0_gcc_dbg_r()                                    (0x00501000U)
#define gr_pri_gpcs_gcc_dbg_r()                                    (0x00419000U)
#define gr_pri_gpcs_gcc_dbg_invalidate_m()                     (U32(0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_cache_control_r()                      (0x0050433cU)
#define gr_pri_gpcs_tpcs_sm_cache_control_r()                      (0x00419b3cU)
#define gr_pri_gpcs_tpcs_sm_cache_control_invalidate_cache_m() (U32(0x1U) << 0U)
#define gr_pri_sked_activity_r()                                   (0x00407054U)
#define gr_pri_gpc0_gpccs_gpc_activity0_r()                        (0x00502c80U)
#define gr_pri_gpc0_gpccs_gpc_activity1_r()                        (0x00502c84U)
#define gr_pri_gpc0_gpccs_gpc_activity2_r()                        (0x00502c88U)
#define gr_pri_gpc0_gpccs_gpc_activity3_r()                        (0x00502c8cU)
#define gr_pri_gpc0_tpc0_tpccs_tpc_activity_0_r()                  (0x00504500U)
#define gr_pri_gpcs_gpccs_gpc_activity_0_r()                       (0x0041ac80U)
#define gr_pri_gpcs_gpccs_gpc_activity_1_r()                       (0x0041ac84U)
#define gr_pri_gpcs_gpccs_gpc_activity_2_r()                       (0x0041ac88U)
#define gr_pri_gpcs_gpccs_gpc_activity_3_r()                       (0x0041ac8cU)
#define gr_pri_gpcs_tpcs_tpccs_tpc_activity_0_r()                  (0x00419d00U)
#define gr_pri_be0_becs_be_activity0_r()                           (0x00410200U)
#define gr_pri_bes_becs_be_activity0_r()                           (0x00408a00U)
#define gr_pri_ds_mpipe_status_r()                                 (0x00405858U)
#define gr_pri_fe_go_idle_info_r()                                 (0x00404194U)
#define gr_pri_fe_chip_def_info_r()                                (0x00404030U)
#define gr_pri_fe_chip_def_info_max_veid_count_v(r)       (((r) >> 0U) & 0xfffU)
#define gr_pri_fe_chip_def_info_max_veid_count_init_v()            (0x00000040U)
#define gr_pri_gpc0_tpc0_tex_m_tex_subunits_status_r()             (0x00504238U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_r()                     (0x00504358U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp0_m()\
				(U32(0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp1_m()\
				(U32(0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp2_m()\
				(U32(0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp3_m()\
				(U32(0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp4_m()\
				(U32(0x1U) << 4U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp5_m()\
				(U32(0x1U) << 5U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp6_m()\
				(U32(0x1U) << 6U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_qrfdp7_m()\
				(U32(0x1U) << 7U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp0_m()\
				(U32(0x1U) << 8U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp1_m()\
				(U32(0x1U) << 9U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp2_m()\
				(U32(0x1U) << 10U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp3_m()\
				(U32(0x1U) << 11U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp4_m()\
				(U32(0x1U) << 12U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp5_m()\
				(U32(0x1U) << 13U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp6_m()\
				(U32(0x1U) << 14U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_qrfdp7_m()\
				(U32(0x1U) << 15U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_corrected_err_total_counter_overflow_v(r)\
				(((r) >> 24U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_uncorrected_err_total_counter_overflow_v(r)\
				(((r) >> 26U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_status_reset_task_f()          (0x40000000U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_corrected_err_count_r()        (0x0050435cU)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_corrected_err_count_total_s()          (16U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_uncorrected_err_count_r()      (0x00504360U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_uncorrected_err_count_total_s()        (16U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_r()                 (0x0050436cU)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_corrected_err_el1_0_m()\
				(U32(0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_corrected_err_el1_1_m()\
				(U32(0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_uncorrected_err_el1_0_m()\
				(U32(0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_uncorrected_err_el1_1_m()\
				(U32(0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_corrected_err_total_counter_overflow_v(r)\
				(((r) >> 8U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_uncorrected_err_total_counter_overflow_v(r)\
				(((r) >> 10U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_status_reset_task_f()      (0x40000000U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_corrected_err_count_r()    (0x00504370U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_corrected_err_count_total_s()      (16U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_uncorrected_err_count_r()  (0x00504374U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_uncorrected_err_count_total_s()    (16U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_r()                  (0x0050464cU)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l0_data_m()\
				(U32(0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l0_predecode_m()\
				(U32(0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l1_data_m()\
				(U32(0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_l1_predecode_m()\
				(U32(0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l0_data_m()\
				(U32(0x1U) << 4U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l0_predecode_m()\
				(U32(0x1U) << 5U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l1_data_m()\
				(U32(0x1U) << 6U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_l1_predecode_m()\
				(U32(0x1U) << 7U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_corrected_err_total_counter_overflow_v(r)\
				(((r) >> 16U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_uncorrected_err_total_counter_overflow_v(r)\
				(((r) >> 18U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_status_reset_task_f()       (0x40000000U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_corrected_err_count_r()     (0x00504650U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_corrected_err_count_total_s()       (16U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_uncorrected_err_count_r()   (0x00504654U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_uncorrected_err_count_total_s()     (16U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_r()                  (0x00504624U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_el1_0_m()\
				(U32(0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_el1_1_m()\
				(U32(0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_el1_0_m()\
				(U32(0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_el1_1_m()\
				(U32(0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_pixrpf_m()\
				(U32(0x1U) << 4U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_miss_fifo_m()\
				(U32(0x1U) << 5U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_pixrpf_m()\
				(U32(0x1U) << 6U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_miss_fifo_m()\
				(U32(0x1U) << 7U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_corrected_err_total_counter_overflow_v(r)\
				(((r) >> 8U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_uncorrected_err_total_counter_overflow_v(r)\
				(((r) >> 10U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_status_reset_task_f()       (0x40000000U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_corrected_err_count_r()     (0x00504628U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_corrected_err_count_total_s()       (16U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_uncorrected_err_count_r()   (0x0050462cU)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_uncorrected_err_count_total_s()     (16U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_r()                     (0x00504638U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_warp_sm0_m()\
				(U32(0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_warp_sm1_m()\
				(U32(0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_barrier_sm0_m()\
				(U32(0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_barrier_sm1_m()\
				(U32(0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_warp_sm0_m()\
				(U32(0x1U) << 4U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_warp_sm1_m()\
				(U32(0x1U) << 5U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_barrier_sm0_m()\
				(U32(0x1U) << 6U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_barrier_sm1_m()\
				(U32(0x1U) << 7U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_corrected_err_total_counter_overflow_v(r)\
				(((r) >> 16U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_uncorrected_err_total_counter_overflow_v(r)\
				(((r) >> 18U) & 0x1U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_status_reset_task_f()          (0x40000000U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_corrected_err_count_r()        (0x0050463cU)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_corrected_err_count_total_s()          (16U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_uncorrected_err_count_r()      (0x00504640U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_uncorrected_err_count_total_s()        (16U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_r()                    (0x00419b54U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp0_task_f()         (0x1U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp1_task_f()         (0x2U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp2_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp2_task_f()         (0x4U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp3_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp3_task_f()         (0x8U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp4_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp4_task_f()        (0x10U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp5_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp5_task_f()        (0x20U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp6_f(v)\
				((U32(v) & 0x1U) << 6U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp6_task_f()        (0x40U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp7_f(v)\
				((U32(v) & 0x1U) << 7U)
#define gr_pri_gpcs_tpcs_sm_lrf_ecc_control_scrub_qrfdp7_task_f()        (0x80U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_r()                    (0x00504354U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp0_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp1_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp2_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp2_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp3_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp3_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp4_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp4_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp5_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp5_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp6_f(v)\
				((U32(v) & 0x1U) << 6U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp6_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp7_f(v)\
				((U32(v) & 0x1U) << 7U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_scrub_qrfdp7_init_f()         (0x0U)
#define gr_pri_gpc0_tpc0_sm_lrf_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 9U)
#define gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_r()                (0x00419b68U)
#define gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_0_task_f()      (0x1U)
#define gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpcs_tpcs_sm_l1_data_ecc_control_scrub_el1_1_task_f()      (0x2U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_r()                (0x00504368U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_0_init_f()      (0x0U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_scrub_el1_1_init_f()      (0x0U)
#define gr_pri_gpc0_tpc0_sm_l1_data_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_r()                 (0x00419e20U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_0_task_f()       (0x1U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_el1_1_task_f()       (0x2U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_pixprf_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_pixprf_task_f()     (0x10U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_miss_fifo_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_pri_gpcs_tpcs_sm_l1_tag_ecc_control_scrub_miss_fifo_task_f()  (0x20U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_r()                 (0x00504620U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_0_init_f()       (0x0U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_el1_1_init_f()       (0x0U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_inject_corrected_err_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_pixprf_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_pixprf_init_f()      (0x0U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_miss_fifo_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_pri_gpc0_tpc0_sm_l1_tag_ecc_control_scrub_miss_fifo_init_f()   (0x0U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_r()                    (0x00419e34U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm0_task_f()       (0x1U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_warp_sm1_task_f()       (0x2U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm0_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm0_task_f()    (0x4U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm1_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpcs_tpcs_sm_cbu_ecc_control_scrub_barrier_sm1_task_f()    (0x8U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_r()                    (0x00504634U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm0_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm0_init_f()       (0x0U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm1_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_warp_sm1_init_f()       (0x0U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm0_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm0_init_f()    (0x0U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm1_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_scrub_barrier_sm1_init_f()    (0x0U)
#define gr_pri_gpc0_tpc0_sm_cbu_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_r()                 (0x00419e48U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_data_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_data_task_f()     (0x1U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_predecode_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l0_predecode_task_f()\
				(0x2U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_data_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_data_task_f()     (0x4U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_predecode_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpcs_tpcs_sm_icache_ecc_control_scrub_l1_predecode_task_f()\
				(0x8U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_r()                 (0x00504648U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_data_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_data_init_f()     (0x0U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_predecode_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l0_predecode_init_f()\
				(0x0U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_data_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_data_init_f()     (0x0U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_predecode_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_scrub_l1_predecode_init_f()\
				(0x0U)
#define gr_pri_gpc0_tpc0_sm_icache_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_pri_gpc0_tpc0_tex_m_routing_r()                         (0x005042c4U)
#define gr_pri_gpc0_tpc0_tex_m_routing_sel_default_f()                    (0x0U)
#define gr_pri_gpc0_tpc0_tex_m_routing_sel_pipe0_f()                      (0x1U)
#define gr_pri_gpc0_tpc0_tex_m_routing_sel_pipe1_f()                      (0x2U)
#define gr_gpc0_tpc0_mpc_hww_esr_r()                               (0x00504430U)
#define gr_gpc0_tpc0_mpc_hww_esr_reset_trigger_f()                 (0x40000000U)
#define gr_gpc0_tpc0_mpc_hww_esr_info_r()                          (0x00504434U)
#define gr_gpc0_tpc0_mpc_hww_esr_info_veid_v(r)            (((r) >> 0U) & 0x3fU)
#define gr_gpc0_tpc0_pe_hww_esr_r()                                (0x00504084U)
#define gr_gpc0_tpc0_pe_hww_esr_reset_task_f()                     (0x40000000U)
#define gr_pri_be0_crop_status1_r()                                (0x00410134U)
#define gr_pri_bes_crop_status1_r()                                (0x00408934U)
#define gr_pri_be0_zrop_status_r()                                 (0x00410048U)
#define gr_pri_be0_zrop_status2_r()                                (0x0041004cU)
#define gr_pri_bes_zrop_status_r()                                 (0x00408848U)
#define gr_pri_bes_zrop_status2_r()                                (0x0040884cU)
#define gr_pipe_bundle_address_r()                                 (0x00400200U)
#define gr_pipe_bundle_address_value_v(r)                (((r) >> 0U) & 0xffffU)
#define gr_pipe_bundle_address_veid_f(v)               ((U32(v) & 0x3fU) << 20U)
#define gr_pipe_bundle_address_veid_w()                                     (0U)
#define gr_pipe_bundle_data_r()                                    (0x00400204U)
#define gr_pipe_bundle_config_r()                                  (0x00400208U)
#define gr_pipe_bundle_config_override_pipe_mode_disabled_f()             (0x0U)
#define gr_pipe_bundle_config_override_pipe_mode_enabled_f()       (0x80000000U)
#define gr_prop_hww_esr_r()                                        (0x00500420U)
#define gr_prop_hww_esr_reset_active_f()                           (0x40000000U)
#define gr_zcull_hww_esr_r()                                       (0x00500900U)
#define gr_zcull_hww_esr_reset_active_f()                          (0x40000000U)
#define gr_setup_hww_esr_r()                                       (0x00500824U)
#define gr_setup_hww_esr_reset_active_f()                          (0x40000000U)
#define gr_pes_hww_esr_r()                                         (0x00503038U)
#define gr_pes_hww_esr_reset_task_f()                              (0x40000000U)
#define gr_fe_hww_esr_r()                                          (0x00404000U)
#define gr_fe_hww_esr_reset_active_f()                             (0x40000000U)
#define gr_fe_hww_esr_en_enable_f()                                (0x80000000U)
#define gr_fe_hww_esr_info_r()                                     (0x004041b0U)
#define gr_gpcs_tpcs_sms_hww_global_esr_report_mask_r()            (0x00419eacU)
#define gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_r()            (0x0050472cU)
#define gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_multiple_warp_errors_report_f()\
				(0x4U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_bpt_int_report_f()   (0x10U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_bpt_pause_report_f() (0x20U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_single_step_complete_report_f()\
				(0x40U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_report_mask_error_in_trap_report_f()\
				(0x100U)
#define gr_gpcs_tpcs_sms_hww_global_esr_r()                        (0x00419eb4U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_r()                        (0x00504734U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_bpt_int_m()            (U32(0x1U) << 4U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_bpt_int_pending_f()              (0x10U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_bpt_pause_m()          (U32(0x1U) << 5U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_bpt_pause_pending_f()            (0x20U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_single_step_complete_m()\
				(U32(0x1U) << 6U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_single_step_complete_pending_f() (0x40U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_multiple_warp_errors_m()\
				(U32(0x1U) << 2U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_multiple_warp_errors_pending_f()  (0x4U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_error_in_trap_m()      (U32(0x1U) << 8U)
#define gr_gpc0_tpc0_sm0_hww_global_esr_error_in_trap_pending_f()       (0x100U)
#define gr_fe_go_idle_timeout_r()                                  (0x00404154U)
#define gr_fe_go_idle_timeout_count_f(v)          ((U32(v) & 0xffffffffU) << 0U)
#define gr_fe_go_idle_timeout_count_disabled_f()                          (0x0U)
#define gr_fe_go_idle_timeout_count_prod_f()                           (0x1800U)
#define gr_fe_object_table_r(i)\
		(nvgpu_safe_add_u32(0x00404200U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_fe_object_table_nvclass_v(r)                  (((r) >> 0U) & 0xffffU)
#define gr_fe_tpc_fs_r(i)\
		(nvgpu_safe_add_u32(0x0040a200U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_fe_tpc_pesmask_r()                                      (0x0040a260U)
#define gr_fe_tpc_pesmask_pesid_f(v)                   ((U32(v) & 0x3fU) << 24U)
#define gr_fe_tpc_pesmask_gpcid_f(v)                   ((U32(v) & 0xffU) << 16U)
#define gr_fe_tpc_pesmask_action_m()                          (U32(0x1U) << 30U)
#define gr_fe_tpc_pesmask_action_write_f()                         (0x40000000U)
#define gr_fe_tpc_pesmask_action_read_f()                                 (0x0U)
#define gr_fe_tpc_pesmask_req_m()                             (U32(0x1U) << 31U)
#define gr_fe_tpc_pesmask_req_send_f()                             (0x80000000U)
#define gr_fe_tpc_pesmask_mask_m()                          (U32(0xffffU) << 0U)
#define gr_pri_mme_shadow_ram_index_r()                            (0x00404488U)
#define gr_pri_mme_shadow_ram_index_nvclass_f(v)      ((U32(v) & 0xffffU) << 0U)
#define gr_pri_mme_shadow_ram_index_method_address_f(v)\
				((U32(v) & 0xfffU) << 16U)
#define gr_pri_mme_shadow_ram_index_fepipe_f(v)         ((U32(v) & 0x1U) << 29U)
#define gr_pri_mme_shadow_ram_index_fepipe_fe0_f()                        (0x0U)
#define gr_pri_mme_shadow_ram_index_write_trigger_f()              (0x80000000U)
#define gr_pri_mme_shadow_ram_data_r()                             (0x0040448cU)
#define gr_mme_hww_esr_r()                                         (0x00404490U)
#define gr_mme_hww_esr_reset_active_f()                            (0x40000000U)
#define gr_mme_hww_esr_en_enable_f()                               (0x80000000U)
#define gr_mme_hww_esr_info_r()                                    (0x00404494U)
#define gr_memfmt_hww_esr_r()                                      (0x00404600U)
#define gr_memfmt_hww_esr_reset_active_f()                         (0x40000000U)
#define gr_memfmt_hww_esr_en_enable_f()                            (0x80000000U)
#define gr_fecs_cpuctl_r()                                         (0x00409100U)
#define gr_fecs_cpuctl_startcpu_f(v)                     ((U32(v) & 0x1U) << 1U)
#define gr_fecs_cpuctl_alias_r()                                   (0x00409130U)
#define gr_fecs_cpuctl_alias_startcpu_f(v)               ((U32(v) & 0x1U) << 1U)
#define gr_fecs_dmactl_r()                                         (0x0040910cU)
#define gr_fecs_dmactl_require_ctx_f(v)                  ((U32(v) & 0x1U) << 0U)
#define gr_fecs_dmactl_dmem_scrubbing_m()                      (U32(0x1U) << 1U)
#define gr_fecs_dmactl_imem_scrubbing_m()                      (U32(0x1U) << 2U)
#define gr_fecs_os_r()                                             (0x00409080U)
#define gr_fecs_idlestate_r()                                      (0x0040904cU)
#define gr_fecs_mailbox0_r()                                       (0x00409040U)
#define gr_fecs_mailbox1_r()                                       (0x00409044U)
#define gr_fecs_irqstat_r()                                        (0x00409008U)
#define gr_fecs_irqmode_r()                                        (0x0040900cU)
#define gr_fecs_irqmask_r()                                        (0x00409018U)
#define gr_fecs_irqdest_r()                                        (0x0040901cU)
#define gr_fecs_curctx_r()                                         (0x00409050U)
#define gr_fecs_nxtctx_r()                                         (0x00409054U)
#define gr_fecs_engctl_r()                                         (0x004090a4U)
#define gr_fecs_debug1_r()                                         (0x00409090U)
#define gr_fecs_debuginfo_r()                                      (0x00409094U)
#define gr_fecs_icd_cmd_r()                                        (0x00409200U)
#define gr_fecs_icd_cmd_opc_s()                                             (4U)
#define gr_fecs_icd_cmd_opc_f(v)                         ((U32(v) & 0xfU) << 0U)
#define gr_fecs_icd_cmd_opc_m()                                (U32(0xfU) << 0U)
#define gr_fecs_icd_cmd_opc_v(r)                            (((r) >> 0U) & 0xfU)
#define gr_fecs_icd_cmd_opc_rreg_f()                                      (0x8U)
#define gr_fecs_icd_cmd_opc_rstat_f()                                     (0xeU)
#define gr_fecs_icd_cmd_idx_f(v)                        ((U32(v) & 0x1fU) << 8U)
#define gr_fecs_icd_rdata_r()                                      (0x0040920cU)
#define gr_fecs_imemc_r(i)\
		(nvgpu_safe_add_u32(0x00409180U, nvgpu_safe_mult_u32((i), 16U)))
#define gr_fecs_imemc_offs_f(v)                         ((U32(v) & 0x3fU) << 2U)
#define gr_fecs_imemc_blk_f(v)                          ((U32(v) & 0xffU) << 8U)
#define gr_fecs_imemc_aincw_f(v)                        ((U32(v) & 0x1U) << 24U)
#define gr_fecs_imemd_r(i)\
		(nvgpu_safe_add_u32(0x00409184U, nvgpu_safe_mult_u32((i), 16U)))
#define gr_fecs_imemt_r(i)\
		(nvgpu_safe_add_u32(0x00409188U, nvgpu_safe_mult_u32((i), 16U)))
#define gr_fecs_imemt_tag_f(v)                        ((U32(v) & 0xffffU) << 0U)
#define gr_fecs_dmemc_r(i)\
		(nvgpu_safe_add_u32(0x004091c0U, nvgpu_safe_mult_u32((i), 8U)))
#define gr_fecs_dmemc_offs_s()                                              (6U)
#define gr_fecs_dmemc_offs_f(v)                         ((U32(v) & 0x3fU) << 2U)
#define gr_fecs_dmemc_offs_m()                                (U32(0x3fU) << 2U)
#define gr_fecs_dmemc_offs_v(r)                            (((r) >> 2U) & 0x3fU)
#define gr_fecs_dmemc_blk_f(v)                          ((U32(v) & 0xffU) << 8U)
#define gr_fecs_dmemc_aincw_f(v)                        ((U32(v) & 0x1U) << 24U)
#define gr_fecs_dmemd_r(i)\
		(nvgpu_safe_add_u32(0x004091c4U, nvgpu_safe_mult_u32((i), 8U)))
#define gr_fecs_dmatrfbase_r()                                     (0x00409110U)
#define gr_fecs_dmatrfmoffs_r()                                    (0x00409114U)
#define gr_fecs_dmatrffboffs_r()                                   (0x0040911cU)
#define gr_fecs_dmatrfcmd_r()                                      (0x00409118U)
#define gr_fecs_dmatrfcmd_imem_f(v)                      ((U32(v) & 0x1U) << 4U)
#define gr_fecs_dmatrfcmd_write_f(v)                     ((U32(v) & 0x1U) << 5U)
#define gr_fecs_dmatrfcmd_size_f(v)                      ((U32(v) & 0x7U) << 8U)
#define gr_fecs_dmatrfcmd_ctxdma_f(v)                   ((U32(v) & 0x7U) << 12U)
#define gr_fecs_bootvec_r()                                        (0x00409104U)
#define gr_fecs_bootvec_vec_f(v)                  ((U32(v) & 0xffffffffU) << 0U)
#define gr_fecs_irqsset_r()                                        (0x00409000U)
#define gr_fecs_falcon_hwcfg_r()                                   (0x00409108U)
#define gr_gpcs_gpccs_irqsset_r()                                  (0x0041a000U)
#define gr_gpcs_gpccs_falcon_hwcfg_r()                             (0x0041a108U)
#define gr_fecs_falcon_rm_r()                                      (0x00409084U)
#define gr_fecs_current_ctx_r()                                    (0x00409b00U)
#define gr_fecs_current_ctx_ptr_f(v)               ((U32(v) & 0xfffffffU) << 0U)
#define gr_fecs_current_ctx_ptr_v(r)                  (((r) >> 0U) & 0xfffffffU)
#define gr_fecs_current_ctx_target_s()                                      (2U)
#define gr_fecs_current_ctx_target_f(v)                 ((U32(v) & 0x3U) << 28U)
#define gr_fecs_current_ctx_target_m()                        (U32(0x3U) << 28U)
#define gr_fecs_current_ctx_target_v(r)                    (((r) >> 28U) & 0x3U)
#define gr_fecs_current_ctx_target_vid_mem_f()                            (0x0U)
#define gr_fecs_current_ctx_target_sys_mem_coh_f()                 (0x20000000U)
#define gr_fecs_current_ctx_target_sys_mem_ncoh_f()                (0x30000000U)
#define gr_fecs_current_ctx_valid_s()                                       (1U)
#define gr_fecs_current_ctx_valid_f(v)                  ((U32(v) & 0x1U) << 31U)
#define gr_fecs_current_ctx_valid_m()                         (U32(0x1U) << 31U)
#define gr_fecs_current_ctx_valid_v(r)                     (((r) >> 31U) & 0x1U)
#define gr_fecs_current_ctx_valid_false_f()                               (0x0U)
#define gr_fecs_method_data_r()                                    (0x00409500U)
#define gr_fecs_method_push_r()                                    (0x00409504U)
#define gr_fecs_method_push_adr_f(v)                   ((U32(v) & 0xfffU) << 0U)
#define gr_fecs_method_push_adr_bind_pointer_v()                   (0x00000003U)
#define gr_fecs_method_push_adr_bind_pointer_f()                          (0x3U)
#define gr_fecs_method_push_adr_discover_image_size_v()            (0x00000010U)
#define gr_fecs_method_push_adr_wfi_golden_save_v()                (0x00000009U)
#define gr_fecs_method_push_adr_restore_golden_v()                 (0x00000015U)
#define gr_fecs_method_push_adr_discover_zcull_image_size_v()      (0x00000016U)
#define gr_fecs_method_push_adr_discover_pm_image_size_v()         (0x00000025U)
#define gr_fecs_method_push_adr_discover_reglist_image_size_v()    (0x00000030U)
#define gr_fecs_method_push_adr_set_reglist_bind_instance_v()      (0x00000031U)
#define gr_fecs_method_push_adr_set_reglist_virtual_address_v()    (0x00000032U)
#define gr_fecs_method_push_adr_stop_ctxsw_v()                     (0x00000038U)
#define gr_fecs_method_push_adr_start_ctxsw_v()                    (0x00000039U)
#define gr_fecs_method_push_adr_set_watchdog_timeout_f()                 (0x21U)
#define gr_fecs_method_push_adr_discover_preemption_image_size_v() (0x0000001aU)
#define gr_fecs_method_push_adr_halt_pipeline_v()                  (0x00000004U)
#define gr_fecs_method_push_adr_configure_interrupt_completion_option_v()\
				(0x0000003aU)
#define gr_fecs_host_int_status_r()                                (0x00409c18U)
#define gr_fecs_host_int_status_fault_during_ctxsw_f(v) ((U32(v) & 0x1U) << 16U)
#define gr_fecs_host_int_status_fault_during_ctxsw_active_v()      (0x00000001U)
#define gr_fecs_host_int_status_umimp_firmware_method_f(v)\
				((U32(v) & 0x1U) << 17U)
#define gr_fecs_host_int_status_umimp_illegal_method_f(v)\
				((U32(v) & 0x1U) << 18U)
#define gr_fecs_host_int_status_watchdog_active_f()                   (0x80000U)
#define gr_fecs_host_int_status_ctxsw_intr_f(v)       ((U32(v) & 0xffffU) << 0U)
#define gr_fecs_host_int_status_ecc_corrected_f(v)      ((U32(v) & 0x1U) << 21U)
#define gr_fecs_host_int_status_ecc_corrected_m()             (U32(0x1U) << 21U)
#define gr_fecs_host_int_status_ecc_uncorrected_f(v)    ((U32(v) & 0x1U) << 22U)
#define gr_fecs_host_int_status_ecc_uncorrected_m()           (U32(0x1U) << 22U)
#define gr_fecs_host_int_clear_r()                                 (0x00409c20U)
#define gr_fecs_host_int_clear_ctxsw_intr0_clear_v()               (0x00000001U)
#define gr_fecs_host_int_clear_ctxsw_intr1_f(v)          ((U32(v) & 0x1U) << 1U)
#define gr_fecs_host_int_clear_ctxsw_intr1_clear_f()                      (0x2U)
#define gr_fecs_host_int_clear_fault_during_ctxsw_clear_v()        (0x00000001U)
#define gr_fecs_host_int_enable_r()                                (0x00409c24U)
#define gr_fecs_host_int_enable_ctxsw_intr0_enable_f()                    (0x1U)
#define gr_fecs_host_int_enable_ctxsw_intr1_enable_f()                    (0x2U)
#define gr_fecs_host_int_enable_fault_during_ctxsw_enable_f()         (0x10000U)
#define gr_fecs_host_int_enable_umimp_firmware_method_enable_f()      (0x20000U)
#define gr_fecs_host_int_enable_umimp_illegal_method_enable_f()       (0x40000U)
#define gr_fecs_host_int_enable_watchdog_enable_f()                   (0x80000U)
#define gr_fecs_host_int_enable_flush_when_busy_enable_f()           (0x100000U)
#define gr_fecs_host_int_enable_ecc_corrected_enable_f()             (0x200000U)
#define gr_fecs_host_int_enable_ecc_uncorrected_enable_f()           (0x400000U)
#define gr_fecs_ctxsw_reset_ctl_r()                                (0x00409614U)
#define gr_fecs_ctxsw_reset_ctl_sys_halt_disabled_f()                     (0x0U)
#define gr_fecs_ctxsw_reset_ctl_gpc_halt_disabled_f()                     (0x0U)
#define gr_fecs_ctxsw_reset_ctl_be_halt_disabled_f()                      (0x0U)
#define gr_fecs_ctxsw_reset_ctl_sys_engine_reset_disabled_f()            (0x10U)
#define gr_fecs_ctxsw_reset_ctl_gpc_engine_reset_disabled_f()            (0x20U)
#define gr_fecs_ctxsw_reset_ctl_be_engine_reset_disabled_f()             (0x40U)
#define gr_fecs_ctxsw_reset_ctl_sys_context_reset_enabled_f()             (0x0U)
#define gr_fecs_ctxsw_reset_ctl_sys_context_reset_disabled_f()          (0x100U)
#define gr_fecs_ctxsw_reset_ctl_gpc_context_reset_enabled_f()             (0x0U)
#define gr_fecs_ctxsw_reset_ctl_gpc_context_reset_disabled_f()          (0x200U)
#define gr_fecs_ctxsw_reset_ctl_be_context_reset_s()                        (1U)
#define gr_fecs_ctxsw_reset_ctl_be_context_reset_f(v)   ((U32(v) & 0x1U) << 10U)
#define gr_fecs_ctxsw_reset_ctl_be_context_reset_m()          (U32(0x1U) << 10U)
#define gr_fecs_ctxsw_reset_ctl_be_context_reset_v(r)      (((r) >> 10U) & 0x1U)
#define gr_fecs_ctxsw_reset_ctl_be_context_reset_enabled_f()              (0x0U)
#define gr_fecs_ctxsw_reset_ctl_be_context_reset_disabled_f()           (0x400U)
#define gr_fecs_ctx_state_store_major_rev_id_r()                   (0x0040960cU)
#define gr_fecs_ctxsw_mailbox_r(i)\
		(nvgpu_safe_add_u32(0x00409800U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_fecs_ctxsw_mailbox__size_1_v()                          (0x00000010U)
#define gr_fecs_ctxsw_mailbox_value_f(v)          ((U32(v) & 0xffffffffU) << 0U)
#define gr_fecs_ctxsw_mailbox_value_pass_v()                       (0x00000001U)
#define gr_fecs_ctxsw_mailbox_value_fail_v()                       (0x00000002U)
#define gr_fecs_ctxsw_mailbox_value_ctxsw_checksum_mismatch_v()    (0x00000021U)
#define gr_fecs_ctxsw_mailbox_set_r(i)\
		(nvgpu_safe_add_u32(0x004098c0U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_fecs_ctxsw_mailbox_set_value_f(v)      ((U32(v) & 0xffffffffU) << 0U)
#define gr_fecs_ctxsw_mailbox_clear_r(i)\
		(nvgpu_safe_add_u32(0x00409840U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_fecs_ctxsw_mailbox_clear_value_f(v)    ((U32(v) & 0xffffffffU) << 0U)
#define gr_fecs_fs_r()                                             (0x00409604U)
#define gr_fecs_fs_num_available_gpcs_s()                                   (5U)
#define gr_fecs_fs_num_available_gpcs_f(v)              ((U32(v) & 0x1fU) << 0U)
#define gr_fecs_fs_num_available_gpcs_m()                     (U32(0x1fU) << 0U)
#define gr_fecs_fs_num_available_gpcs_v(r)                 (((r) >> 0U) & 0x1fU)
#define gr_fecs_fs_num_available_fbps_s()                                   (5U)
#define gr_fecs_fs_num_available_fbps_f(v)             ((U32(v) & 0x1fU) << 16U)
#define gr_fecs_fs_num_available_fbps_m()                    (U32(0x1fU) << 16U)
#define gr_fecs_fs_num_available_fbps_v(r)                (((r) >> 16U) & 0x1fU)
#define gr_fecs_cfg_r()                                            (0x00409620U)
#define gr_fecs_cfg_imem_sz_v(r)                           (((r) >> 0U) & 0xffU)
#define gr_fecs_rc_lanes_r()                                       (0x00409880U)
#define gr_fecs_rc_lanes_num_chains_s()                                     (6U)
#define gr_fecs_rc_lanes_num_chains_f(v)                ((U32(v) & 0x3fU) << 0U)
#define gr_fecs_rc_lanes_num_chains_m()                       (U32(0x3fU) << 0U)
#define gr_fecs_rc_lanes_num_chains_v(r)                   (((r) >> 0U) & 0x3fU)
#define gr_fecs_ctxsw_status_1_r()                                 (0x00409400U)
#define gr_fecs_ctxsw_status_1_arb_busy_s()                                 (1U)
#define gr_fecs_ctxsw_status_1_arb_busy_f(v)            ((U32(v) & 0x1U) << 12U)
#define gr_fecs_ctxsw_status_1_arb_busy_m()                   (U32(0x1U) << 12U)
#define gr_fecs_ctxsw_status_1_arb_busy_v(r)               (((r) >> 12U) & 0x1U)
#define gr_fecs_arb_ctx_adr_r()                                    (0x00409a24U)
#define gr_fecs_new_ctx_r()                                        (0x00409b04U)
#define gr_fecs_new_ctx_ptr_s()                                            (28U)
#define gr_fecs_new_ctx_ptr_f(v)                   ((U32(v) & 0xfffffffU) << 0U)
#define gr_fecs_new_ctx_ptr_m()                          (U32(0xfffffffU) << 0U)
#define gr_fecs_new_ctx_ptr_v(r)                      (((r) >> 0U) & 0xfffffffU)
#define gr_fecs_new_ctx_target_s()                                          (2U)
#define gr_fecs_new_ctx_target_f(v)                     ((U32(v) & 0x3U) << 28U)
#define gr_fecs_new_ctx_target_m()                            (U32(0x3U) << 28U)
#define gr_fecs_new_ctx_target_v(r)                        (((r) >> 28U) & 0x3U)
#define gr_fecs_new_ctx_valid_s()                                           (1U)
#define gr_fecs_new_ctx_valid_f(v)                      ((U32(v) & 0x1U) << 31U)
#define gr_fecs_new_ctx_valid_m()                             (U32(0x1U) << 31U)
#define gr_fecs_new_ctx_valid_v(r)                         (((r) >> 31U) & 0x1U)
#define gr_fecs_arb_ctx_ptr_r()                                    (0x00409a0cU)
#define gr_fecs_arb_ctx_ptr_ptr_s()                                        (28U)
#define gr_fecs_arb_ctx_ptr_ptr_f(v)               ((U32(v) & 0xfffffffU) << 0U)
#define gr_fecs_arb_ctx_ptr_ptr_m()                      (U32(0xfffffffU) << 0U)
#define gr_fecs_arb_ctx_ptr_ptr_v(r)                  (((r) >> 0U) & 0xfffffffU)
#define gr_fecs_arb_ctx_ptr_target_s()                                      (2U)
#define gr_fecs_arb_ctx_ptr_target_f(v)                 ((U32(v) & 0x3U) << 28U)
#define gr_fecs_arb_ctx_ptr_target_m()                        (U32(0x3U) << 28U)
#define gr_fecs_arb_ctx_ptr_target_v(r)                    (((r) >> 28U) & 0x3U)
#define gr_fecs_arb_ctx_cmd_r()                                    (0x00409a10U)
#define gr_fecs_arb_ctx_cmd_cmd_s()                                         (5U)
#define gr_fecs_arb_ctx_cmd_cmd_f(v)                    ((U32(v) & 0x1fU) << 0U)
#define gr_fecs_arb_ctx_cmd_cmd_m()                           (U32(0x1fU) << 0U)
#define gr_fecs_arb_ctx_cmd_cmd_v(r)                       (((r) >> 0U) & 0x1fU)
#define gr_fecs_ctxsw_status_fe_0_r()                              (0x00409c00U)
#define gr_gpc0_gpccs_ctxsw_status_gpc_0_r()                       (0x00502c04U)
#define gr_gpc0_gpccs_ctxsw_status_1_r()                           (0x00502400U)
#define gr_fecs_ctxsw_idlestate_r()                                (0x00409420U)
#define gr_fecs_feature_override_ecc_r()                           (0x00409658U)
#define gr_fecs_feature_override_ecc_sm_lrf_v(r)            (((r) >> 0U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_lrf_override_v(r)   (((r) >> 3U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_l1_data_v(r)        (((r) >> 4U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_l1_data_override_v(r)\
				(((r) >> 7U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_l1_tag_v(r)         (((r) >> 8U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_l1_tag_override_v(r)\
				(((r) >> 11U) & 0x1U)
#define gr_fecs_feature_override_ecc_ltc_v(r)              (((r) >> 12U) & 0x1U)
#define gr_fecs_feature_override_ecc_ltc_override_v(r)     (((r) >> 15U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_cbu_v(r)           (((r) >> 20U) & 0x1U)
#define gr_fecs_feature_override_ecc_sm_cbu_override_v(r)  (((r) >> 23U) & 0x1U)
#define gr_fecs_feature_override_ecc_1_r()                         (0x0040965cU)
#define gr_fecs_feature_override_ecc_1_sm_l0_icache_v(r)    (((r) >> 0U) & 0x1U)
#define gr_fecs_feature_override_ecc_1_sm_l0_icache_override_v(r)\
				(((r) >> 1U) & 0x1U)
#define gr_fecs_feature_override_ecc_1_sm_l1_icache_v(r)    (((r) >> 2U) & 0x1U)
#define gr_fecs_feature_override_ecc_1_sm_l1_icache_override_v(r)\
				(((r) >> 3U) & 0x1U)
#define gr_gpc0_gpccs_ctxsw_idlestate_r()                          (0x00502420U)
#define gr_rstr2d_gpc_map_r(i)\
		(nvgpu_safe_add_u32(0x0040780cU, nvgpu_safe_mult_u32((i), 4U)))
#define gr_rstr2d_map_table_cfg_r()                                (0x004078bcU)
#define gr_rstr2d_map_table_cfg_row_offset_f(v)         ((U32(v) & 0xffU) << 0U)
#define gr_rstr2d_map_table_cfg_num_entries_f(v)        ((U32(v) & 0xffU) << 8U)
#define gr_pd_hww_esr_r()                                          (0x00406018U)
#define gr_pd_hww_esr_reset_active_f()                             (0x40000000U)
#define gr_pd_hww_esr_en_enable_f()                                (0x80000000U)
#define gr_pd_num_tpc_per_gpc_r(i)\
		(nvgpu_safe_add_u32(0x00406028U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_pd_num_tpc_per_gpc__size_1_v()                          (0x00000004U)
#define gr_pd_num_tpc_per_gpc_count0_f(v)                ((U32(v) & 0xfU) << 0U)
#define gr_pd_num_tpc_per_gpc_count1_f(v)                ((U32(v) & 0xfU) << 4U)
#define gr_pd_num_tpc_per_gpc_count2_f(v)                ((U32(v) & 0xfU) << 8U)
#define gr_pd_num_tpc_per_gpc_count3_f(v)               ((U32(v) & 0xfU) << 12U)
#define gr_pd_num_tpc_per_gpc_count4_f(v)               ((U32(v) & 0xfU) << 16U)
#define gr_pd_num_tpc_per_gpc_count5_f(v)               ((U32(v) & 0xfU) << 20U)
#define gr_pd_num_tpc_per_gpc_count6_f(v)               ((U32(v) & 0xfU) << 24U)
#define gr_pd_num_tpc_per_gpc_count7_f(v)               ((U32(v) & 0xfU) << 28U)
#define gr_pd_ab_dist_cfg0_r()                                     (0x004064c0U)
#define gr_pd_ab_dist_cfg0_timeslice_enable_en_f()                 (0x80000000U)
#define gr_pd_ab_dist_cfg0_timeslice_enable_dis_f()                       (0x0U)
#define gr_pd_ab_dist_cfg1_r()                                     (0x004064c4U)
#define gr_pd_ab_dist_cfg1_max_batches_init_f()                        (0xffffU)
#define gr_pd_ab_dist_cfg1_max_output_f(v)           ((U32(v) & 0xffffU) << 16U)
#define gr_pd_ab_dist_cfg1_max_output_granularity_v()              (0x00000080U)
#define gr_pd_ab_dist_cfg2_r()                                     (0x004064c8U)
#define gr_pd_ab_dist_cfg2_token_limit_f(v)           ((U32(v) & 0x1fffU) << 0U)
#define gr_pd_ab_dist_cfg2_token_limit_init_v()                    (0x00000380U)
#define gr_pd_ab_dist_cfg2_state_limit_f(v)          ((U32(v) & 0x1fffU) << 16U)
#define gr_pd_ab_dist_cfg2_state_limit_scc_bundle_granularity_v()  (0x00000020U)
#define gr_pd_ab_dist_cfg2_state_limit_min_gpm_fifo_depths_v()     (0x00000302U)
#define gr_pd_dist_skip_table_r(i)\
		(nvgpu_safe_add_u32(0x004064d0U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_pd_dist_skip_table__size_1_v()                          (0x00000008U)
#define gr_pd_dist_skip_table_gpc_4n0_mask_f(v)         ((U32(v) & 0xffU) << 0U)
#define gr_pd_dist_skip_table_gpc_4n1_mask_f(v)         ((U32(v) & 0xffU) << 8U)
#define gr_pd_dist_skip_table_gpc_4n2_mask_f(v)        ((U32(v) & 0xffU) << 16U)
#define gr_pd_dist_skip_table_gpc_4n3_mask_f(v)        ((U32(v) & 0xffU) << 24U)
#define gr_ds_debug_r()                                            (0x00405800U)
#define gr_ds_debug_timeslice_mode_disable_f()                            (0x0U)
#define gr_ds_debug_timeslice_mode_enable_f()                       (0x8000000U)
#define gr_ds_zbc_color_r_r()                                      (0x00405804U)
#define gr_ds_zbc_color_r_val_f(v)                ((U32(v) & 0xffffffffU) << 0U)
#define gr_ds_zbc_color_g_r()                                      (0x00405808U)
#define gr_ds_zbc_color_g_val_f(v)                ((U32(v) & 0xffffffffU) << 0U)
#define gr_ds_zbc_color_b_r()                                      (0x0040580cU)
#define gr_ds_zbc_color_b_val_f(v)                ((U32(v) & 0xffffffffU) << 0U)
#define gr_ds_zbc_color_a_r()                                      (0x00405810U)
#define gr_ds_zbc_color_a_val_f(v)                ((U32(v) & 0xffffffffU) << 0U)
#define gr_ds_zbc_color_fmt_r()                                    (0x00405814U)
#define gr_ds_zbc_color_fmt_val_f(v)                    ((U32(v) & 0x7fU) << 0U)
#define gr_ds_zbc_color_fmt_val_invalid_f()                               (0x0U)
#define gr_ds_zbc_color_fmt_val_zero_v()                           (0x00000001U)
#define gr_ds_zbc_color_fmt_val_unorm_one_v()                      (0x00000002U)
#define gr_ds_zbc_color_fmt_val_rf32_gf32_bf32_af32_v()            (0x00000004U)
#define gr_ds_zbc_color_fmt_val_a8_b8_g8_r8_v()                    (0x00000028U)
#define gr_ds_zbc_z_r()                                            (0x00405818U)
#define gr_ds_zbc_z_val_s()                                                (32U)
#define gr_ds_zbc_z_val_f(v)                      ((U32(v) & 0xffffffffU) << 0U)
#define gr_ds_zbc_z_val_m()                             (U32(0xffffffffU) << 0U)
#define gr_ds_zbc_z_val_v(r)                         (((r) >> 0U) & 0xffffffffU)
#define gr_ds_zbc_z_val__init_v()                                  (0x00000000U)
#define gr_ds_zbc_z_val__init_f()                                         (0x0U)
#define gr_ds_zbc_z_fmt_r()                                        (0x0040581cU)
#define gr_ds_zbc_z_fmt_val_f(v)                         ((U32(v) & 0x1U) << 0U)
#define gr_ds_zbc_z_fmt_val_invalid_f()                                   (0x0U)
#define gr_ds_zbc_z_fmt_val_fp32_v()                               (0x00000001U)
#define gr_ds_zbc_tbl_index_r()                                    (0x00405820U)
#define gr_ds_zbc_tbl_index_val_f(v)                     ((U32(v) & 0xfU) << 0U)
#define gr_ds_zbc_tbl_ld_r()                                       (0x00405824U)
#define gr_ds_zbc_tbl_ld_select_c_f()                                     (0x0U)
#define gr_ds_zbc_tbl_ld_select_z_f()                                     (0x1U)
#define gr_ds_zbc_tbl_ld_action_write_f()                                 (0x0U)
#define gr_ds_zbc_tbl_ld_trigger_active_f()                               (0x4U)
#define gr_ds_tga_constraintlogic_beta_r()                         (0x00405830U)
#define gr_ds_tga_constraintlogic_beta_cbsize_f(v)  ((U32(v) & 0x3fffffU) << 0U)
#define gr_ds_tga_constraintlogic_alpha_r()                        (0x0040585cU)
#define gr_ds_tga_constraintlogic_alpha_cbsize_f(v)   ((U32(v) & 0xffffU) << 0U)
#define gr_ds_hww_esr_r()                                          (0x00405840U)
#define gr_ds_hww_esr_reset_s()                                             (1U)
#define gr_ds_hww_esr_reset_f(v)                        ((U32(v) & 0x1U) << 30U)
#define gr_ds_hww_esr_reset_m()                               (U32(0x1U) << 30U)
#define gr_ds_hww_esr_reset_v(r)                           (((r) >> 30U) & 0x1U)
#define gr_ds_hww_esr_reset_task_v()                               (0x00000001U)
#define gr_ds_hww_esr_reset_task_f()                               (0x40000000U)
#define gr_ds_hww_esr_en_enabled_f()                               (0x80000000U)
#define gr_ds_hww_esr_2_r()                                        (0x00405848U)
#define gr_ds_hww_esr_2_reset_s()                                           (1U)
#define gr_ds_hww_esr_2_reset_f(v)                      ((U32(v) & 0x1U) << 30U)
#define gr_ds_hww_esr_2_reset_m()                             (U32(0x1U) << 30U)
#define gr_ds_hww_esr_2_reset_v(r)                         (((r) >> 30U) & 0x1U)
#define gr_ds_hww_esr_2_reset_task_v()                             (0x00000001U)
#define gr_ds_hww_esr_2_reset_task_f()                             (0x40000000U)
#define gr_ds_hww_esr_2_en_enabled_f()                             (0x80000000U)
#define gr_ds_hww_report_mask_r()                                  (0x00405844U)
#define gr_ds_hww_report_mask_sph0_err_report_f()                         (0x1U)
#define gr_ds_hww_report_mask_sph1_err_report_f()                         (0x2U)
#define gr_ds_hww_report_mask_sph2_err_report_f()                         (0x4U)
#define gr_ds_hww_report_mask_sph3_err_report_f()                         (0x8U)
#define gr_ds_hww_report_mask_sph4_err_report_f()                        (0x10U)
#define gr_ds_hww_report_mask_sph5_err_report_f()                        (0x20U)
#define gr_ds_hww_report_mask_sph6_err_report_f()                        (0x40U)
#define gr_ds_hww_report_mask_sph7_err_report_f()                        (0x80U)
#define gr_ds_hww_report_mask_sph8_err_report_f()                       (0x100U)
#define gr_ds_hww_report_mask_sph9_err_report_f()                       (0x200U)
#define gr_ds_hww_report_mask_sph10_err_report_f()                      (0x400U)
#define gr_ds_hww_report_mask_sph11_err_report_f()                      (0x800U)
#define gr_ds_hww_report_mask_sph12_err_report_f()                     (0x1000U)
#define gr_ds_hww_report_mask_sph13_err_report_f()                     (0x2000U)
#define gr_ds_hww_report_mask_sph14_err_report_f()                     (0x4000U)
#define gr_ds_hww_report_mask_sph15_err_report_f()                     (0x8000U)
#define gr_ds_hww_report_mask_sph16_err_report_f()                    (0x10000U)
#define gr_ds_hww_report_mask_sph17_err_report_f()                    (0x20000U)
#define gr_ds_hww_report_mask_sph18_err_report_f()                    (0x40000U)
#define gr_ds_hww_report_mask_sph19_err_report_f()                    (0x80000U)
#define gr_ds_hww_report_mask_sph20_err_report_f()                   (0x100000U)
#define gr_ds_hww_report_mask_sph21_err_report_f()                   (0x200000U)
#define gr_ds_hww_report_mask_sph22_err_report_f()                   (0x400000U)
#define gr_ds_hww_report_mask_sph23_err_report_f()                   (0x800000U)
#define gr_ds_hww_report_mask_2_r()                                (0x0040584cU)
#define gr_ds_hww_report_mask_2_sph24_err_report_f()                      (0x1U)
#define gr_ds_num_tpc_per_gpc_r(i)\
		(nvgpu_safe_add_u32(0x00405870U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_scc_debug_r()                                           (0x00408000U)
#define gr_scc_debug_pagepool_invalidates_m()                  (U32(0x1U) << 9U)
#define gr_scc_debug_pagepool_invalidates_disable_f()                   (0x200U)
#define gr_scc_debug_pagepool_invalidates_enable_f()                      (0x0U)
#define gr_scc_bundle_cb_base_r()                                  (0x00408004U)
#define gr_scc_bundle_cb_base_addr_39_8_f(v)      ((U32(v) & 0xffffffffU) << 0U)
#define gr_scc_bundle_cb_base_addr_39_8_align_bits_v()             (0x00000008U)
#define gr_scc_bundle_cb_size_r()                                  (0x00408008U)
#define gr_scc_bundle_cb_size_div_256b_f(v)            ((U32(v) & 0x7ffU) << 0U)
#define gr_scc_bundle_cb_size_div_256b__prod_v()                   (0x00000030U)
#define gr_scc_bundle_cb_size_div_256b_byte_granularity_v()        (0x00000100U)
#define gr_scc_bundle_cb_size_valid_false_v()                      (0x00000000U)
#define gr_scc_bundle_cb_size_valid_false_f()                             (0x0U)
#define gr_scc_bundle_cb_size_valid_true_f()                       (0x80000000U)
#define gr_scc_pagepool_base_r()                                   (0x0040800cU)
#define gr_scc_pagepool_base_addr_39_8_f(v)       ((U32(v) & 0xffffffffU) << 0U)
#define gr_scc_pagepool_base_addr_39_8_align_bits_v()              (0x00000008U)
#define gr_scc_pagepool_r()                                        (0x00408010U)
#define gr_scc_pagepool_total_pages_f(v)               ((U32(v) & 0x3ffU) << 0U)
#define gr_scc_pagepool_total_pages_hwmax_v()                      (0x00000000U)
#define gr_scc_pagepool_total_pages_hwmax_value_v()                (0x00000200U)
#define gr_scc_pagepool_total_pages_byte_granularity_v()           (0x00000100U)
#define gr_scc_pagepool_max_valid_pages_s()                                (10U)
#define gr_scc_pagepool_max_valid_pages_f(v)          ((U32(v) & 0x3ffU) << 10U)
#define gr_scc_pagepool_max_valid_pages_m()                 (U32(0x3ffU) << 10U)
#define gr_scc_pagepool_max_valid_pages_v(r)             (((r) >> 10U) & 0x3ffU)
#define gr_scc_pagepool_valid_true_f()                             (0x80000000U)
#define gr_scc_hww_esr_r()                                         (0x00408030U)
#define gr_scc_hww_esr_reset_active_f()                            (0x40000000U)
#define gr_scc_hww_esr_en_enable_f()                               (0x80000000U)
#define gr_ssync_hww_esr_r()                                       (0x00405a14U)
#define gr_ssync_hww_esr_reset_active_f()                          (0x40000000U)
#define gr_ssync_hww_esr_en_enable_f()                             (0x80000000U)
#define gr_sked_hww_esr_r()                                        (0x00407020U)
#define gr_sked_hww_esr_reset_active_f()                           (0x40000000U)
#define gr_sked_hww_esr_en_r()                                     (0x00407024U)
#define gr_sked_hww_esr_en_skedcheck18_l1_config_too_small_m()\
				(U32(0x1U) << 25U)
#define gr_sked_hww_esr_en_skedcheck18_l1_config_too_small_disabled_f()   (0x0U)
#define gr_sked_hww_esr_en_skedcheck18_l1_config_too_small_enabled_f()\
				(0x2000000U)
#define gr_crop_hww_esr_r()                                        (0x00410144U)
#define gr_crop_hww_esr_reset_active_f()                           (0x40000000U)
#define gr_zrop_hww_esr_r()                                        (0x00410070U)
#define gr_zrop_hww_esr_reset_active_f()                           (0x40000000U)
#define gr_cwd_fs_r()                                              (0x00405b00U)
#define gr_cwd_fs_num_gpcs_f(v)                         ((U32(v) & 0xffU) << 0U)
#define gr_cwd_fs_num_tpcs_f(v)                         ((U32(v) & 0xffU) << 8U)
#define gr_cwd_gpc_tpc_id_r(i)\
		(nvgpu_safe_add_u32(0x00405b60U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_cwd_gpc_tpc_id_tpc0_s()                                          (4U)
#define gr_cwd_gpc_tpc_id_tpc0_f(v)                      ((U32(v) & 0xfU) << 0U)
#define gr_cwd_gpc_tpc_id_gpc0_s()                                          (4U)
#define gr_cwd_gpc_tpc_id_gpc0_f(v)                      ((U32(v) & 0xfU) << 4U)
#define gr_cwd_gpc_tpc_id_tpc1_f(v)                      ((U32(v) & 0xfU) << 8U)
#define gr_cwd_sm_id_r(i)\
		(nvgpu_safe_add_u32(0x00405ba0U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_cwd_sm_id__size_1_v()                                   (0x00000010U)
#define gr_cwd_sm_id_tpc0_f(v)                          ((U32(v) & 0xffU) << 0U)
#define gr_cwd_sm_id_tpc1_f(v)                          ((U32(v) & 0xffU) << 8U)
#define gr_gpc0_fs_gpc_r()                                         (0x00502608U)
#define gr_gpc0_fs_gpc_num_available_tpcs_v(r)             (((r) >> 0U) & 0x1fU)
#define gr_gpc0_fs_gpc_num_available_zculls_v(r)          (((r) >> 16U) & 0x1fU)
#define gr_gpc0_cfg_r()                                            (0x00502620U)
#define gr_gpc0_cfg_imem_sz_v(r)                           (((r) >> 0U) & 0xffU)
#define gr_gpccs_rc_lanes_r()                                      (0x00502880U)
#define gr_gpccs_rc_lanes_num_chains_s()                                    (6U)
#define gr_gpccs_rc_lanes_num_chains_f(v)               ((U32(v) & 0x3fU) << 0U)
#define gr_gpccs_rc_lanes_num_chains_m()                      (U32(0x3fU) << 0U)
#define gr_gpccs_rc_lanes_num_chains_v(r)                  (((r) >> 0U) & 0x3fU)
#define gr_gpccs_rc_lane_size_r()                                  (0x00502910U)
#define gr_gpccs_rc_lane_size_v_s()                                        (24U)
#define gr_gpccs_rc_lane_size_v_f(v)                ((U32(v) & 0xffffffU) << 0U)
#define gr_gpccs_rc_lane_size_v_m()                       (U32(0xffffffU) << 0U)
#define gr_gpccs_rc_lane_size_v_v(r)                   (((r) >> 0U) & 0xffffffU)
#define gr_gpccs_rc_lane_size_v_0_v()                              (0x00000000U)
#define gr_gpccs_rc_lane_size_v_0_f()                                     (0x0U)
#define gr_gpc0_zcull_fs_r()                                       (0x00500910U)
#define gr_gpc0_zcull_fs_num_sms_f(v)                  ((U32(v) & 0x1ffU) << 0U)
#define gr_gpc0_zcull_fs_num_active_banks_f(v)          ((U32(v) & 0xfU) << 16U)
#define gr_gpc0_zcull_ram_addr_r()                                 (0x00500914U)
#define gr_gpc0_zcull_ram_addr_tiles_per_hypertile_row_per_gpc_f(v)\
				((U32(v) & 0xfU) << 0U)
#define gr_gpc0_zcull_ram_addr_row_offset_f(v)           ((U32(v) & 0xfU) << 8U)
#define gr_gpc0_zcull_sm_num_rcp_r()                               (0x00500918U)
#define gr_gpc0_zcull_sm_num_rcp_conservative_f(v)  ((U32(v) & 0xffffffU) << 0U)
#define gr_gpc0_zcull_sm_num_rcp_conservative__max_v()             (0x00800000U)
#define gr_gpc0_zcull_total_ram_size_r()                           (0x00500920U)
#define gr_gpc0_zcull_total_ram_size_num_aliquots_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_zcull_zcsize_r(i)\
		(nvgpu_safe_add_u32(0x00500a04U, nvgpu_safe_mult_u32((i), 32U)))
#define gr_gpc0_zcull_zcsize_height_subregion__multiple_v()        (0x00000040U)
#define gr_gpc0_zcull_zcsize_width_subregion__multiple_v()         (0x00000010U)
#define gr_gpc0_gpm_pd_sm_id_r(i)\
		(nvgpu_safe_add_u32(0x00500c10U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpc0_gpm_pd_sm_id_id_f(v)                    ((U32(v) & 0xffU) << 0U)
#define gr_gpc0_gpm_pd_pes_tpc_id_mask_r(i)\
		(nvgpu_safe_add_u32(0x00500c30U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpc0_gpm_pd_pes_tpc_id_mask_mask_v(r)           (((r) >> 0U) & 0xffU)
#define gr_gpc0_tpc0_pe_cfg_smid_r()                               (0x00504088U)
#define gr_gpc0_tpc0_pe_cfg_smid_value_f(v)           ((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_tpc0_sm_cfg_r()                                    (0x00504608U)
#define gr_gpc0_tpc0_sm_cfg_tpc_id_f(v)               ((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_tpc0_sm_cfg_tpc_id_v(r)                  (((r) >> 0U) & 0xffffU)
#define gr_gpc0_tpc0_sm_arch_r()                                   (0x00504330U)
#define gr_gpc0_tpc0_sm_arch_warp_count_v(r)               (((r) >> 0U) & 0xffU)
#define gr_gpc0_tpc0_sm_arch_spa_version_v(r)             (((r) >> 8U) & 0xfffU)
#define gr_gpc0_tpc0_sm_arch_sm_version_v(r)             (((r) >> 20U) & 0xfffU)
#define gr_gpc0_ppc0_pes_vsc_strem_r()                             (0x00503018U)
#define gr_gpc0_ppc0_pes_vsc_strem_master_pe_m()               (U32(0x1U) << 0U)
#define gr_gpc0_ppc0_pes_vsc_strem_master_pe_true_f()                     (0x1U)
#define gr_gpc0_ppc0_cbm_beta_cb_size_r()                          (0x005030c0U)
#define gr_gpc0_ppc0_cbm_beta_cb_size_v_f(v)        ((U32(v) & 0x3fffffU) << 0U)
#define gr_gpc0_ppc0_cbm_beta_cb_size_v_m()               (U32(0x3fffffU) << 0U)
#define gr_gpc0_ppc0_cbm_beta_cb_size_v_default_v()                (0x00000800U)
#define gr_gpc0_ppc0_cbm_beta_cb_size_v_gfxp_v()                   (0x00001100U)
#define gr_gpc0_ppc0_cbm_beta_cb_size_v_granularity_v()            (0x00000020U)
#define gr_gpc0_ppc0_cbm_beta_cb_offset_r()                        (0x005030f4U)
#define gr_gpc0_ppc0_cbm_alpha_cb_size_r()                         (0x005030e4U)
#define gr_gpc0_ppc0_cbm_alpha_cb_size_v_f(v)         ((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_ppc0_cbm_alpha_cb_size_v_m()                (U32(0xffffU) << 0U)
#define gr_gpc0_ppc0_cbm_alpha_cb_size_v_default_v()               (0x00000800U)
#define gr_gpc0_ppc0_cbm_alpha_cb_size_v_granularity_v()           (0x00000020U)
#define gr_gpc0_ppc0_cbm_alpha_cb_offset_r()                       (0x005030f8U)
#define gr_gpc0_ppc0_cbm_beta_steady_state_cb_size_r()             (0x005030f0U)
#define gr_gpc0_ppc0_cbm_beta_steady_state_cb_size_v_f(v)\
				((U32(v) & 0x3fffffU) << 0U)
#define gr_gpc0_ppc0_cbm_beta_steady_state_cb_size_v_default_v()   (0x00000800U)
#define gr_gpcs_tpcs_tex_rm_cb_0_r()                               (0x00419e00U)
#define gr_gpcs_tpcs_tex_rm_cb_0_base_addr_43_12_f(v)\
				((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_tpcs_tex_rm_cb_1_r()                               (0x00419e04U)
#define gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_s()                         (21U)
#define gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_f(v) ((U32(v) & 0x1fffffU) << 0U)
#define gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_m()        (U32(0x1fffffU) << 0U)
#define gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_v(r)    (((r) >> 0U) & 0x1fffffU)
#define gr_gpcs_tpcs_tex_rm_cb_1_size_div_128b_granularity_f()           (0x80U)
#define gr_gpcs_tpcs_tex_rm_cb_1_valid_s()                                  (1U)
#define gr_gpcs_tpcs_tex_rm_cb_1_valid_f(v)             ((U32(v) & 0x1U) << 31U)
#define gr_gpcs_tpcs_tex_rm_cb_1_valid_m()                    (U32(0x1U) << 31U)
#define gr_gpcs_tpcs_tex_rm_cb_1_valid_v(r)                (((r) >> 31U) & 0x1U)
#define gr_gpcs_tpcs_tex_rm_cb_1_valid_true_f()                    (0x80000000U)
#define gr_gpccs_falcon_addr_r()                                   (0x0041a0acU)
#define gr_gpccs_falcon_addr_lsb_s()                                        (6U)
#define gr_gpccs_falcon_addr_lsb_f(v)                   ((U32(v) & 0x3fU) << 0U)
#define gr_gpccs_falcon_addr_lsb_m()                          (U32(0x3fU) << 0U)
#define gr_gpccs_falcon_addr_lsb_v(r)                      (((r) >> 0U) & 0x3fU)
#define gr_gpccs_falcon_addr_lsb_init_v()                          (0x00000000U)
#define gr_gpccs_falcon_addr_lsb_init_f()                                 (0x0U)
#define gr_gpccs_falcon_addr_msb_s()                                        (6U)
#define gr_gpccs_falcon_addr_msb_f(v)                   ((U32(v) & 0x3fU) << 6U)
#define gr_gpccs_falcon_addr_msb_m()                          (U32(0x3fU) << 6U)
#define gr_gpccs_falcon_addr_msb_v(r)                      (((r) >> 6U) & 0x3fU)
#define gr_gpccs_falcon_addr_msb_init_v()                          (0x00000000U)
#define gr_gpccs_falcon_addr_msb_init_f()                                 (0x0U)
#define gr_gpccs_falcon_addr_ext_s()                                       (12U)
#define gr_gpccs_falcon_addr_ext_f(v)                  ((U32(v) & 0xfffU) << 0U)
#define gr_gpccs_falcon_addr_ext_m()                         (U32(0xfffU) << 0U)
#define gr_gpccs_falcon_addr_ext_v(r)                     (((r) >> 0U) & 0xfffU)
#define gr_gpccs_cpuctl_r()                                        (0x0041a100U)
#define gr_gpccs_cpuctl_startcpu_f(v)                    ((U32(v) & 0x1U) << 1U)
#define gr_gpccs_dmactl_r()                                        (0x0041a10cU)
#define gr_gpccs_dmactl_require_ctx_f(v)                 ((U32(v) & 0x1U) << 0U)
#define gr_gpccs_dmactl_dmem_scrubbing_m()                     (U32(0x1U) << 1U)
#define gr_gpccs_dmactl_imem_scrubbing_m()                     (U32(0x1U) << 2U)
#define gr_gpccs_imemc_r(i)\
		(nvgpu_safe_add_u32(0x0041a180U, nvgpu_safe_mult_u32((i), 16U)))
#define gr_gpccs_imemc_offs_f(v)                        ((U32(v) & 0x3fU) << 2U)
#define gr_gpccs_imemc_blk_f(v)                         ((U32(v) & 0xffU) << 8U)
#define gr_gpccs_imemc_aincw_f(v)                       ((U32(v) & 0x1U) << 24U)
#define gr_gpccs_imemd_r(i)\
		(nvgpu_safe_add_u32(0x0041a184U, nvgpu_safe_mult_u32((i), 16U)))
#define gr_gpccs_imemt_r(i)\
		(nvgpu_safe_add_u32(0x0041a188U, nvgpu_safe_mult_u32((i), 16U)))
#define gr_gpccs_imemt__size_1_v()                                 (0x00000004U)
#define gr_gpccs_imemt_tag_f(v)                       ((U32(v) & 0xffffU) << 0U)
#define gr_gpccs_dmemc_r(i)\
		(nvgpu_safe_add_u32(0x0041a1c0U, nvgpu_safe_mult_u32((i), 8U)))
#define gr_gpccs_dmemc_offs_f(v)                        ((U32(v) & 0x3fU) << 2U)
#define gr_gpccs_dmemc_blk_f(v)                         ((U32(v) & 0xffU) << 8U)
#define gr_gpccs_dmemc_aincw_f(v)                       ((U32(v) & 0x1U) << 24U)
#define gr_gpccs_dmemd_r(i)\
		(nvgpu_safe_add_u32(0x0041a1c4U, nvgpu_safe_mult_u32((i), 8U)))
#define gr_gpccs_ctxsw_mailbox_r(i)\
		(nvgpu_safe_add_u32(0x0041a800U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpccs_ctxsw_mailbox__size_1_v()                         (0x00000010U)
#define gr_gpccs_ctxsw_mailbox_value_f(v)         ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpc0_gpccs_ctxsw_mailbox_r(i)\
		(nvgpu_safe_add_u32(0x00502800U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_bundle_cb_base_r()                            (0x00418e24U)
#define gr_gpcs_swdx_bundle_cb_base_addr_39_8_s()                          (32U)
#define gr_gpcs_swdx_bundle_cb_base_addr_39_8_f(v)\
				((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_swdx_bundle_cb_base_addr_39_8_m()       (U32(0xffffffffU) << 0U)
#define gr_gpcs_swdx_bundle_cb_base_addr_39_8_v(r)   (((r) >> 0U) & 0xffffffffU)
#define gr_gpcs_swdx_bundle_cb_base_addr_39_8_init_v()             (0x00000000U)
#define gr_gpcs_swdx_bundle_cb_base_addr_39_8_init_f()                    (0x0U)
#define gr_gpcs_swdx_bundle_cb_size_r()                            (0x00418e28U)
#define gr_gpcs_swdx_bundle_cb_size_div_256b_s()                           (11U)
#define gr_gpcs_swdx_bundle_cb_size_div_256b_f(v)      ((U32(v) & 0x7ffU) << 0U)
#define gr_gpcs_swdx_bundle_cb_size_div_256b_m()             (U32(0x7ffU) << 0U)
#define gr_gpcs_swdx_bundle_cb_size_div_256b_v(r)         (((r) >> 0U) & 0x7ffU)
#define gr_gpcs_swdx_bundle_cb_size_div_256b_init_v()              (0x00000030U)
#define gr_gpcs_swdx_bundle_cb_size_div_256b_init_f()                    (0x30U)
#define gr_gpcs_swdx_bundle_cb_size_valid_s()                               (1U)
#define gr_gpcs_swdx_bundle_cb_size_valid_f(v)          ((U32(v) & 0x1U) << 31U)
#define gr_gpcs_swdx_bundle_cb_size_valid_m()                 (U32(0x1U) << 31U)
#define gr_gpcs_swdx_bundle_cb_size_valid_v(r)             (((r) >> 31U) & 0x1U)
#define gr_gpcs_swdx_bundle_cb_size_valid_false_v()                (0x00000000U)
#define gr_gpcs_swdx_bundle_cb_size_valid_false_f()                       (0x0U)
#define gr_gpcs_swdx_bundle_cb_size_valid_true_v()                 (0x00000001U)
#define gr_gpcs_swdx_bundle_cb_size_valid_true_f()                 (0x80000000U)
#define gr_gpc0_swdx_rm_spill_buffer_size_r()                      (0x005001dcU)
#define gr_gpc0_swdx_rm_spill_buffer_size_256b_f(v)   ((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_swdx_rm_spill_buffer_size_256b_default_v()         (0x00000170U)
#define gr_gpc0_swdx_rm_spill_buffer_size_256b_byte_granularity_v()\
				(0x00000100U)
#define gr_gpc0_swdx_rm_spill_buffer_addr_r()                      (0x005001d8U)
#define gr_gpc0_swdx_rm_spill_buffer_addr_39_8_f(v)\
				((U32(v) & 0xffffffffU) << 0U)
#define gr_gpc0_swdx_rm_spill_buffer_addr_39_8_align_bits_v()      (0x00000008U)
#define gr_gpcs_swdx_beta_cb_ctrl_r()                              (0x004181e4U)
#define gr_gpcs_swdx_beta_cb_ctrl_cbes_reserve_f(v)    ((U32(v) & 0xfffU) << 0U)
#define gr_gpcs_swdx_beta_cb_ctrl_cbes_reserve_gfxp_v()            (0x00000100U)
#define gr_gpcs_ppcs_cbm_beta_cb_ctrl_r()                          (0x0041befcU)
#define gr_gpcs_ppcs_cbm_beta_cb_ctrl_cbes_reserve_f(v)\
				((U32(v) & 0xfffU) << 0U)
#define gr_gpcs_ppcs_cbm_debug_r()                                 (0x0041bec4U)
#define gr_gpcs_ppcs_cbm_debug_invalidate_alpha_m()            (U32(0x1U) << 0U)
#define gr_gpcs_ppcs_cbm_debug_invalidate_alpha_disable_f()               (0x0U)
#define gr_gpcs_ppcs_cbm_debug_invalidate_alpha_enable_f()                (0x1U)
#define gr_gpcs_ppcs_cbm_debug_invalidate_beta_m()             (U32(0x1U) << 1U)
#define gr_gpcs_ppcs_cbm_debug_invalidate_beta_disable_f()                (0x0U)
#define gr_gpcs_ppcs_cbm_debug_invalidate_beta_enable_f()                 (0x2U)
#define gr_gpcs_swdx_tc_beta_cb_size_r(i)\
		(nvgpu_safe_add_u32(0x00418ea0U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_tc_beta_cb_size_v_f(v)         ((U32(v) & 0x3fffffU) << 0U)
#define gr_gpcs_swdx_tc_beta_cb_size_v_m()                (U32(0x3fffffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_color_r_r(i)\
		(nvgpu_safe_add_u32(0x00418010U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_dss_zbc_color_r__size_1_v()                   (0x0000000fU)
#define gr_gpcs_swdx_dss_zbc_color_r_val_f(v)     ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_color_g_r(i)\
		(nvgpu_safe_add_u32(0x0041804cU, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_dss_zbc_color_g_val_f(v)     ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_color_b_r(i)\
		(nvgpu_safe_add_u32(0x00418088U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_dss_zbc_color_b_val_f(v)     ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_color_a_r(i)\
		(nvgpu_safe_add_u32(0x004180c4U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_dss_zbc_color_a_val_f(v)     ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_c_01_to_04_format_r()                 (0x00418100U)
#define gr_gpcs_swdx_dss_zbc_z_r(i)\
		(nvgpu_safe_add_u32(0x00418110U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_dss_zbc_z__size_1_v()                         (0x0000000fU)
#define gr_gpcs_swdx_dss_zbc_z_val_f(v)           ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_z_01_to_04_format_r()                 (0x0041814cU)
#define gr_gpcs_swdx_dss_zbc_s_r(i)\
		(nvgpu_safe_add_u32(0x0041815cU, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_swdx_dss_zbc_s__size_1_v()                         (0x0000000fU)
#define gr_gpcs_swdx_dss_zbc_s_val_f(v)                 ((U32(v) & 0xffU) << 0U)
#define gr_gpcs_swdx_dss_zbc_s_01_to_04_format_r()                 (0x00418198U)
#define gr_gpcs_swdx_spill_unit_r()                                (0x00418e9cU)
#define gr_gpcs_swdx_spill_unit_spill_buffer_cache_mgmt_mode_m()\
				(U32(0x1U) << 16U)
#define gr_gpcs_swdx_spill_unit_spill_buffer_cache_mgmt_mode_disabled_f() (0x0U)
#define gr_gpcs_swdx_spill_unit_spill_buffer_cache_mgmt_mode_enabled_f()\
				(0x10000U)
#define gr_gpcs_setup_attrib_cb_base_r()                           (0x00418810U)
#define gr_gpcs_setup_attrib_cb_base_addr_39_12_f(v)\
				((U32(v) & 0xfffffffU) << 0U)
#define gr_gpcs_setup_attrib_cb_base_addr_39_12_align_bits_v()     (0x0000000cU)
#define gr_gpcs_setup_attrib_cb_base_valid_true_f()                (0x80000000U)
#define gr_crstr_gpc_map_r(i)\
		(nvgpu_safe_add_u32(0x00418b08U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_crstr_gpc_map_tile0_f(v)                     ((U32(v) & 0x1fU) << 0U)
#define gr_crstr_gpc_map_tile1_f(v)                     ((U32(v) & 0x1fU) << 5U)
#define gr_crstr_gpc_map_tile2_f(v)                    ((U32(v) & 0x1fU) << 10U)
#define gr_crstr_gpc_map_tile3_f(v)                    ((U32(v) & 0x1fU) << 15U)
#define gr_crstr_gpc_map_tile4_f(v)                    ((U32(v) & 0x1fU) << 20U)
#define gr_crstr_gpc_map_tile5_f(v)                    ((U32(v) & 0x1fU) << 25U)
#define gr_crstr_map_table_cfg_r()                                 (0x00418bb8U)
#define gr_crstr_map_table_cfg_row_offset_f(v)          ((U32(v) & 0xffU) << 0U)
#define gr_crstr_map_table_cfg_num_entries_f(v)         ((U32(v) & 0xffU) << 8U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_r(i)\
		(nvgpu_safe_add_u32(0x00418980U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_0_f(v)   ((U32(v) & 0x7U) << 0U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_1_f(v)   ((U32(v) & 0x7U) << 4U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_2_f(v)   ((U32(v) & 0x7U) << 8U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_3_f(v)  ((U32(v) & 0x7U) << 12U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_4_f(v)  ((U32(v) & 0x7U) << 16U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_5_f(v)  ((U32(v) & 0x7U) << 20U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_6_f(v)  ((U32(v) & 0x7U) << 24U)
#define gr_gpcs_zcull_sm_in_gpc_number_map_tile_7_f(v)  ((U32(v) & 0x7U) << 28U)
#define gr_gpcs_gpm_pd_cfg_r()                                     (0x00418c6cU)
#define gr_gpcs_gcc_pagepool_base_r()                              (0x00419004U)
#define gr_gpcs_gcc_pagepool_base_addr_39_8_f(v)  ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpcs_gcc_pagepool_r()                                   (0x00419008U)
#define gr_gpcs_gcc_pagepool_total_pages_f(v)          ((U32(v) & 0x3ffU) << 0U)
#define gr_gpcs_tpcs_pe_vaf_r()                                    (0x0041980cU)
#define gr_gpcs_tpcs_pe_vaf_fast_mode_switch_true_f()                    (0x10U)
#define gr_gpcs_tpcs_pe_pin_cb_global_base_addr_r()                (0x00419848U)
#define gr_gpcs_tpcs_pe_pin_cb_global_base_addr_v_f(v)\
				((U32(v) & 0xfffffffU) << 0U)
#define gr_gpcs_tpcs_pe_pin_cb_global_base_addr_valid_f(v)\
				((U32(v) & 0x1U) << 28U)
#define gr_gpcs_tpcs_pe_pin_cb_global_base_addr_valid_true_f()     (0x10000000U)
#define gr_gpcs_tpcs_mpc_vtg_debug_r()                             (0x00419c00U)
#define gr_gpcs_tpcs_mpc_vtg_debug_timeslice_mode_disabled_f()            (0x0U)
#define gr_gpcs_tpcs_mpc_vtg_debug_timeslice_mode_enabled_f()             (0x8U)
#define gr_gpcs_tpcs_mpc_pix_debug_r()                             (0x00419c04U)
#define gr_gpcs_tpcs_mpc_pix_debug_cta_subpartition_skew_m()  (U32(0x1U) << 13U)
#define gr_gpcs_tpcs_mpc_pix_debug_cta_subpartition_skew_disable_f()      (0x0U)
#define gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_r()               (0x00419c2cU)
#define gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_v_f(v)\
				((U32(v) & 0xfffffffU) << 0U)
#define gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_valid_f(v)\
				((U32(v) & 0x1U) << 28U)
#define gr_gpcs_tpcs_mpc_vtg_cb_global_base_addr_valid_true_f()    (0x10000000U)
#define gr_gpcs_tpcs_sms_hww_warp_esr_report_mask_r()              (0x00419ea8U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_r()              (0x00504728U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_stack_error_report_f()  (0x2U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_api_stack_error_report_f()\
				(0x4U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_pc_wrap_report_f()     (0x10U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_misaligned_pc_report_f()\
				(0x20U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_pc_overflow_report_f() (0x40U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_misaligned_reg_report_f()\
				(0x100U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_illegal_instr_encoding_report_f()\
				(0x200U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_illegal_instr_param_report_f()\
				(0x800U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_oor_reg_report_f()   (0x2000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_oor_addr_report_f()  (0x4000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_misaligned_addr_report_f()\
				(0x8000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_invalid_addr_space_report_f()\
				(0x10000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_invalid_const_addr_ldc_report_f()\
				(0x40000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_mmu_fault_report_f()\
				(0x800000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_stack_overflow_report_f()\
				(0x400000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_report_mask_mmu_nack_report_f()\
				(0x4000000U)
#define gr_gpcs_tpcs_tpccs_tpc_exception_en_r()                    (0x00419d0cU)
#define gr_gpcs_tpcs_tpccs_tpc_exception_en_sm_enabled_f()                (0x2U)
#define gr_gpcs_tpcs_tpccs_tpc_exception_en_tex_enabled_f()               (0x1U)
#define gr_gpcs_tpcs_tpccs_tpc_exception_en_mpc_enabled_f()              (0x10U)
#define gr_gpcs_tpcs_tpccs_tpc_exception_en_pe_enabled_f()                (0x4U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_en_r()                    (0x0050450cU)
#define gr_gpc0_tpc0_tpccs_tpc_exception_en_sm_v(r)         (((r) >> 1U) & 0x1U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_en_sm_enabled_f()                (0x2U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_en_mpc_enabled_f()              (0x10U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_en_pe_enabled_f()                (0x4U)
#define gr_gpcs_gpccs_gpc_exception_en_r()                         (0x0041ac94U)
#define gr_gpcs_gpccs_gpc_exception_en_gcc_f(v)          ((U32(v) & 0x1U) << 2U)
#define gr_gpcs_gpccs_gpc_exception_en_tpc_f(v)        ((U32(v) & 0xffU) << 16U)
#define gr_gpcs_gpccs_gpc_exception_en_gpccs_f(v)       ((U32(v) & 0x1U) << 14U)
#define gr_gpcs_gpccs_gpc_exception_en_gpcmmu_f(v)      ((U32(v) & 0x1U) << 15U)
#define gr_gpc0_gpccs_gpc_exception_r()                            (0x00502c90U)
#define gr_gpc0_gpccs_gpc_exception_prop_m()                   (U32(0x1U) << 0U)
#define gr_gpc0_gpccs_gpc_exception_zcull_m()                  (U32(0x1U) << 1U)
#define gr_gpc0_gpccs_gpc_exception_setup_m()                  (U32(0x1U) << 3U)
#define gr_gpc0_gpccs_gpc_exception_pes0_m()                   (U32(0x1U) << 4U)
#define gr_gpc0_gpccs_gpc_exception_pes1_m()                   (U32(0x1U) << 5U)
#define gr_gpc0_gpccs_gpc_exception_gcc_v(r)                (((r) >> 2U) & 0x1U)
#define gr_gpc0_gpccs_gpc_exception_tpc_v(r)              (((r) >> 16U) & 0xffU)
#define gr_gpc0_gpccs_gpc_exception_tpc_0_pending_v()              (0x00000001U)
#define gr_gpc0_gpccs_gpc_exception_gpccs_f(v)          ((U32(v) & 0x1U) << 14U)
#define gr_gpc0_gpccs_gpc_exception_gpccs_m()                 (U32(0x1U) << 14U)
#define gr_gpc0_gpccs_gpc_exception_gpccs_pending_f()                  (0x4000U)
#define gr_gpc0_gpccs_gpc_exception_gpcmmu_f(v)         ((U32(v) & 0x1U) << 15U)
#define gr_gpc0_gpccs_gpc_exception_gpcmmu_m()                (U32(0x1U) << 15U)
#define gr_gpc0_gpccs_gpc_exception_gpcmmu_pending_f()                 (0x8000U)
#define gr_pri_gpc0_gcc_l15_ecc_control_r()                        (0x00501044U)
#define gr_pri_gpc0_gcc_l15_ecc_control_inject_corrected_err_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_pri_gpc0_gcc_l15_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_pri_gpc0_gcc_l15_ecc_status_r()                         (0x00501048U)
#define gr_pri_gpc0_gcc_l15_ecc_status_corrected_err_bank0_m() (U32(0x1U) << 0U)
#define gr_pri_gpc0_gcc_l15_ecc_status_corrected_err_bank1_m() (U32(0x1U) << 1U)
#define gr_pri_gpc0_gcc_l15_ecc_status_uncorrected_err_bank0_m()\
				(U32(0x1U) << 4U)
#define gr_pri_gpc0_gcc_l15_ecc_status_uncorrected_err_bank1_m()\
				(U32(0x1U) << 5U)
#define gr_pri_gpc0_gcc_l15_ecc_status_corrected_err_total_counter_overflow_v(r)\
				(((r) >> 8U) & 0x1U)
#define gr_pri_gpc0_gcc_l15_ecc_status_uncorrected_err_total_counter_overflow_v(r)\
				(((r) >> 10U) & 0x1U)
#define gr_pri_gpc0_gcc_l15_ecc_status_reset_task_f()              (0x40000000U)
#define gr_pri_gpc0_gcc_l15_ecc_corrected_err_count_r()            (0x0050104cU)
#define gr_pri_gpc0_gcc_l15_ecc_corrected_err_count_total_s()              (16U)
#define gr_pri_gpc0_gcc_l15_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_pri_gpc0_gcc_l15_ecc_uncorrected_err_count_r()          (0x00501054U)
#define gr_pri_gpc0_gcc_l15_ecc_uncorrected_err_count_total_s()            (16U)
#define gr_pri_gpc0_gcc_l15_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_gpc0_tpc0_tpccs_tpc_exception_r()                       (0x00504508U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_tex_v(r)           (((r) >> 0U) & 0x1U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_tex_pending_v()           (0x00000001U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_sm_v(r)            (((r) >> 1U) & 0x1U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_sm_pending_v()            (0x00000001U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_mpc_m()               (U32(0x1U) << 4U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_mpc_pending_f()                 (0x10U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_pe_m()                (U32(0x1U) << 2U)
#define gr_gpc0_tpc0_tpccs_tpc_exception_pe_pending_f()                   (0x4U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_r()                         (0x00504704U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_m()       (U32(0x1U) << 0U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_v(r)   (((r) >> 0U) & 0x1U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_on_v()        (0x00000001U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_on_f()               (0x1U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_off_v()       (0x00000000U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_debugger_mode_off_f()              (0x0U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_stop_trigger_m()       (U32(0x1U) << 31U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_stop_trigger_enable_f()     (0x80000000U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_stop_trigger_disable_f()           (0x0U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_single_step_mode_m()    (U32(0x1U) << 3U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_single_step_mode_enable_f()        (0x8U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_single_step_mode_disable_f()       (0x0U)
#define gr_gpc0_tpc0_sm0_dbgr_control0_run_trigger_task_f()        (0x40000000U)
#define gr_gpc0_tpc0_sm0_warp_valid_mask_0_r()                     (0x00504708U)
#define gr_gpc0_tpc0_sm0_warp_valid_mask_1_r()                     (0x0050470cU)
#define gr_gpc0_tpc0_sm0_dbgr_bpt_pause_mask_0_r()                 (0x00504710U)
#define gr_gpc0_tpc0_sm0_dbgr_bpt_pause_mask_1_r()                 (0x00504714U)
#define gr_gpc0_tpc0_sm0_dbgr_bpt_trap_mask_0_r()                  (0x00504718U)
#define gr_gpc0_tpc0_sm0_dbgr_bpt_trap_mask_1_r()                  (0x0050471cU)
#define gr_gpcs_tpcs_sms_dbgr_bpt_pause_mask_0_r()                 (0x00419e90U)
#define gr_gpcs_tpcs_sms_dbgr_bpt_pause_mask_1_r()                 (0x00419e94U)
#define gr_gpcs_tpcs_sms_dbgr_status0_r()                          (0x00419e80U)
#define gr_gpc0_tpc0_sm0_dbgr_status0_r()                          (0x00504700U)
#define gr_gpc0_tpc0_sm0_dbgr_status0_sm_in_trap_mode_v(r)  (((r) >> 0U) & 0x1U)
#define gr_gpc0_tpc0_sm0_dbgr_status0_locked_down_v(r)      (((r) >> 4U) & 0x1U)
#define gr_gpc0_tpc0_sm0_dbgr_status0_locked_down_true_v()         (0x00000001U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_r()                          (0x00504730U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_v(r)         (((r) >> 0U) & 0xffffU)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_none_v()               (0x00000000U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_none_f()                      (0x0U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_stack_error_f()               (0x1U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_api_stack_error_f()           (0x2U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_pc_wrap_f()                   (0x4U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_misaligned_pc_f()             (0x5U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_pc_overflow_f()               (0x6U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_misaligned_reg_f()            (0x8U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_illegal_instr_encoding_f()    (0x9U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_illegal_instr_param_f()       (0xbU)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_oor_reg_f()                   (0xdU)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_oor_addr_f()                  (0xeU)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_misaligned_addr_f()           (0xfU)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_invalid_addr_space_f()       (0x10U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_invalid_const_addr_ldc_f()   (0x12U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_stack_overflow_f()           (0x16U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_mmu_fault_f()                (0x17U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_tex_format_f()               (0x18U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_tex_layout_f()               (0x19U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_error_mmu_nack_f()                 (0x20U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_wrap_id_m()            (U32(0xffU) << 16U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_addr_error_type_m()     (U32(0xfU) << 24U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_addr_error_type_none_f()            (0x0U)
#define gr_gpc0_tpc0_sm_tpc_esr_sm_sel_r()                         (0x0050460cU)
#define gr_gpc0_tpc0_sm_tpc_esr_sm_sel_sm0_error_v(r)       (((r) >> 0U) & 0x1U)
#define gr_gpc0_tpc0_sm_tpc_esr_sm_sel_sm1_error_v(r)       (((r) >> 1U) & 0x1U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_pc_r()                       (0x00504738U)
#define gr_gpc0_tpc0_sm0_hww_warp_esr_pc_hi_r()                    (0x0050473cU)
#define gr_gpc0_tpc0_sm_halfctl_ctrl_r()                           (0x005043a0U)
#define gr_gpcs_tpcs_sm_halfctl_ctrl_r()                           (0x00419ba0U)
#define gr_gpcs_tpcs_sm_halfctl_ctrl_sctl_read_quad_ctl_m()    (U32(0x1U) << 4U)
#define gr_gpcs_tpcs_sm_halfctl_ctrl_sctl_read_quad_ctl_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_gpc0_tpc0_sm_debug_sfe_control_r()                      (0x005043b0U)
#define gr_gpcs_tpcs_sm_debug_sfe_control_r()                      (0x00419bb0U)
#define gr_gpcs_tpcs_sm_debug_sfe_control_read_half_ctl_m()    (U32(0x1U) << 0U)
#define gr_gpcs_tpcs_sm_debug_sfe_control_read_half_ctl_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_gpcs_tpcs_pes_vsc_vpc_r()                               (0x0041be08U)
#define gr_gpcs_tpcs_pes_vsc_vpc_fast_mode_switch_true_f()                (0x4U)
#define gr_ppcs_wwdx_map_gpc_map_r(i)\
		(nvgpu_safe_add_u32(0x0041bf00U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_ppcs_wwdx_map_table_cfg_r()                             (0x0041bfd0U)
#define gr_ppcs_wwdx_map_table_cfg_row_offset_f(v)      ((U32(v) & 0xffU) << 0U)
#define gr_ppcs_wwdx_map_table_cfg_num_entries_f(v)     ((U32(v) & 0xffU) << 8U)
#define gr_ppcs_wwdx_map_table_cfg_normalized_num_entries_f(v)\
				((U32(v) & 0x1fU) << 16U)
#define gr_ppcs_wwdx_map_table_cfg_normalized_shift_value_f(v)\
				((U32(v) & 0x7U) << 21U)
#define gr_gpcs_ppcs_wwdx_sm_num_rcp_r()                           (0x0041bfd4U)
#define gr_gpcs_ppcs_wwdx_sm_num_rcp_conservative_f(v)\
				((U32(v) & 0xffffffU) << 0U)
#define gr_ppcs_wwdx_map_table_cfg_coeff_r(i)\
		(nvgpu_safe_add_u32(0x0041bfb0U, nvgpu_safe_mult_u32((i), 4U)))
#define gr_ppcs_wwdx_map_table_cfg_coeff__size_1_v()               (0x00000005U)
#define gr_ppcs_wwdx_map_table_cfg_coeff_0_mod_value_f(v)\
				((U32(v) & 0xffU) << 0U)
#define gr_ppcs_wwdx_map_table_cfg_coeff_1_mod_value_f(v)\
				((U32(v) & 0xffU) << 8U)
#define gr_ppcs_wwdx_map_table_cfg_coeff_2_mod_value_f(v)\
				((U32(v) & 0xffU) << 16U)
#define gr_ppcs_wwdx_map_table_cfg_coeff_3_mod_value_f(v)\
				((U32(v) & 0xffU) << 24U)
#define gr_bes_zrop_settings_r()                                   (0x00408850U)
#define gr_bes_zrop_settings_num_active_ltcs_f(v)        ((U32(v) & 0xfU) << 0U)
#define gr_be0_crop_debug3_r()                                     (0x00410108U)
#define gr_bes_crop_debug3_r()                                     (0x00408908U)
#define gr_bes_crop_debug3_comp_vdc_4to2_disable_m()          (U32(0x1U) << 31U)
#define gr_bes_crop_debug3_blendopt_read_suppress_m()          (U32(0x1U) << 1U)
#define gr_bes_crop_debug3_blendopt_read_suppress_disabled_f()            (0x0U)
#define gr_bes_crop_debug3_blendopt_read_suppress_enabled_f()             (0x2U)
#define gr_bes_crop_debug3_blendopt_fill_override_m()          (U32(0x1U) << 2U)
#define gr_bes_crop_debug3_blendopt_fill_override_disabled_f()            (0x0U)
#define gr_bes_crop_debug3_blendopt_fill_override_enabled_f()             (0x4U)
#define gr_bes_crop_debug4_r()                                     (0x0040894cU)
#define gr_bes_crop_debug4_clamp_fp_blend_m()                 (U32(0x1U) << 18U)
#define gr_bes_crop_debug4_clamp_fp_blend_to_inf_f()                      (0x0U)
#define gr_bes_crop_debug4_clamp_fp_blend_to_maxval_f()               (0x40000U)
#define gr_bes_crop_settings_r()                                   (0x00408958U)
#define gr_bes_crop_settings_num_active_ltcs_f(v)        ((U32(v) & 0xfU) << 0U)
#define gr_zcull_bytes_per_aliquot_per_gpu_v()                     (0x00000020U)
#define gr_zcull_save_restore_header_bytes_per_gpc_v()             (0x00000020U)
#define gr_zcull_save_restore_subregion_header_bytes_per_gpc_v()   (0x000000c0U)
#define gr_zcull_subregion_qty_v()                                 (0x00000010U)
#define gr_gpcs_tpcs_tex_in_dbg_r()                                (0x00419a00U)
#define gr_gpcs_tpcs_tex_in_dbg_tsl1_rvch_invalidate_f(v)\
				((U32(v) & 0x1U) << 19U)
#define gr_gpcs_tpcs_tex_in_dbg_tsl1_rvch_invalidate_m()      (U32(0x1U) << 19U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_r()                             (0x00419bf0U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_ld_f(v) ((U32(v) & 0x1U) << 5U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_ld_m()        (U32(0x1U) << 5U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_st_f(v)\
				((U32(v) & 0x1U) << 10U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_cache_surface_st_m()       (U32(0x1U) << 10U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_always_cut_collector_m()   (U32(0x1U) << 28U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_always_cut_collector_disable_f()       (0x0U)
#define gr_gpcs_tpcs_sm_l1tag_ctrl_always_cut_collector_enable_f() (0x10000000U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control_sel0_r()        (0x00584200U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control_sel1_r()        (0x00584204U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control0_r()            (0x00584208U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control1_r()            (0x00584210U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control2_r()            (0x00584214U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control3_r()            (0x00584218U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control4_r()            (0x0058421cU)
#define gr_egpc0_etpc0_sm_dsm_perf_counter_control5_r()            (0x0058420cU)
#define gr_egpc0_etpc0_sm_dsm_perf_counter0_control_r()            (0x00584220U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter1_control_r()            (0x00584224U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter2_control_r()            (0x00584228U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter3_control_r()            (0x0058422cU)
#define gr_egpc0_etpc0_sm_dsm_perf_counter4_control_r()            (0x00584230U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter5_control_r()            (0x00584234U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter6_control_r()            (0x00584238U)
#define gr_egpc0_etpc0_sm_dsm_perf_counter7_control_r()            (0x0058423cU)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter_status_s0_r()          (0x00584600U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter_status_s1_r()          (0x00584604U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter0_s0_r()                (0x00584624U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter1_s0_r()                (0x00584628U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter2_s0_r()                (0x0058462cU)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter3_s0_r()                (0x00584630U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter0_s1_r()                (0x00584634U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter1_s1_r()                (0x00584638U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter2_s1_r()                (0x0058463cU)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter3_s1_r()                (0x00584640U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter0_s2_r()                (0x00584644U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter1_s2_r()                (0x00584648U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter2_s2_r()                (0x0058464cU)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter3_s2_r()                (0x00584650U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter0_s3_r()                (0x00584654U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter1_s3_r()                (0x00584658U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter2_s3_r()                (0x0058465cU)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter3_s3_r()                (0x00584660U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter4_r()                   (0x00584614U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter5_r()                   (0x00584618U)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter6_r()                   (0x0058461cU)
#define gr_egpc0_etpc0_sm0_dsm_perf_counter7_r()                   (0x00584620U)
#define gr_fe_pwr_mode_r()                                         (0x00404170U)
#define gr_fe_pwr_mode_mode_auto_f()                                      (0x0U)
#define gr_fe_pwr_mode_mode_force_on_f()                                  (0x2U)
#define gr_fe_pwr_mode_req_v(r)                             (((r) >> 4U) & 0x1U)
#define gr_fe_pwr_mode_req_send_f()                                      (0x10U)
#define gr_fe_pwr_mode_req_done_v()                                (0x00000000U)
#define gr_gpcs_pri_mmu_ctrl_r()                                   (0x00418880U)
#define gr_gpcs_pri_mmu_ctrl_vm_pg_size_m()                    (U32(0x1U) << 0U)
#define gr_gpcs_pri_mmu_ctrl_use_pdb_big_page_size_m()        (U32(0x1U) << 11U)
#define gr_gpcs_pri_mmu_ctrl_vol_fault_m()                     (U32(0x1U) << 1U)
#define gr_gpcs_pri_mmu_ctrl_comp_fault_m()                    (U32(0x1U) << 2U)
#define gr_gpcs_pri_mmu_ctrl_miss_gran_m()                     (U32(0x3U) << 3U)
#define gr_gpcs_pri_mmu_ctrl_cache_mode_m()                    (U32(0x3U) << 5U)
#define gr_gpcs_pri_mmu_ctrl_mmu_aperture_m()                 (U32(0x3U) << 28U)
#define gr_gpcs_pri_mmu_ctrl_mmu_vol_m()                      (U32(0x1U) << 30U)
#define gr_gpcs_pri_mmu_ctrl_mmu_disable_m()                  (U32(0x1U) << 31U)
#define gr_gpcs_pri_mmu_ctrl_atomic_capability_mode_m()       (U32(0x3U) << 24U)
#define gr_gpcs_pri_mmu_ctrl_atomic_capability_sys_ncoh_mode_m()\
				(U32(0x1U) << 27U)
#define gr_gpcs_pri_mmu_pm_unit_mask_r()                           (0x00418890U)
#define gr_gpcs_pri_mmu_pm_req_mask_r()                            (0x00418894U)
#define gr_gpcs_pri_mmu_debug_ctrl_r()                             (0x004188b0U)
#define gr_gpcs_pri_mmu_debug_ctrl_debug_v(r)              (((r) >> 16U) & 0x1U)
#define gr_gpcs_pri_mmu_debug_ctrl_debug_enabled_v()               (0x00000001U)
#define gr_gpcs_pri_mmu_debug_wr_r()                               (0x004188b4U)
#define gr_gpcs_pri_mmu_debug_rd_r()                               (0x004188b8U)
#define gr_gpcs_mmu_num_active_ltcs_r()                            (0x004188acU)
#define gr_gpcs_tpcs_sms_dbgr_control0_r()                         (0x00419e84U)
#define gr_fe_gfxp_wfi_timeout_r()                                 (0x004041c0U)
#define gr_fe_gfxp_wfi_timeout_count_f(v)         ((U32(v) & 0xffffffffU) << 0U)
#define gr_fe_gfxp_wfi_timeout_count_disabled_f()                         (0x0U)
#define gr_fe_gfxp_wfi_timeout_count_init_f()                           (0x800U)
#define gr_gpcs_tpcs_sm_texio_control_r()                          (0x00419bd8U)
#define gr_gpcs_tpcs_sm_texio_control_oor_addr_check_mode_f(v)\
				((U32(v) & 0x7U) << 8U)
#define gr_gpcs_tpcs_sm_texio_control_oor_addr_check_mode_m()  (U32(0x7U) << 8U)
#define gr_gpcs_tpcs_sm_texio_control_oor_addr_check_mode_arm_63_48_match_f()\
				(0x100U)
#define gr_gpcs_tpcs_sm_disp_ctrl_r()                              (0x00419ba4U)
#define gr_gpcs_tpcs_sm_disp_ctrl_re_suppress_m()             (U32(0x3U) << 11U)
#define gr_gpcs_tpcs_sm_disp_ctrl_re_suppress_disable_f()              (0x1000U)
#define gr_gpcs_tc_debug0_r()                                      (0x00418708U)
#define gr_gpcs_tc_debug0_limit_coalesce_buffer_size_f(v)\
				((U32(v) & 0x1ffU) << 0U)
#define gr_gpcs_tc_debug0_limit_coalesce_buffer_size_m()     (U32(0x1ffU) << 0U)
#define gr_gpc0_mmu_gpcmmu_global_esr_r()                          (0x00500324U)
#define gr_gpc0_mmu_gpcmmu_global_esr_ecc_corrected_f(v) ((U32(v) & 0x1U) << 0U)
#define gr_gpc0_mmu_gpcmmu_global_esr_ecc_corrected_m()        (U32(0x1U) << 0U)
#define gr_gpc0_mmu_gpcmmu_global_esr_ecc_uncorrected_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_gpc0_mmu_gpcmmu_global_esr_ecc_uncorrected_m()      (U32(0x1U) << 1U)
#define gr_gpc0_mmu_l1tlb_ecc_control_r()                          (0x00500310U)
#define gr_gpc0_mmu_l1tlb_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_gpc0_mmu_l1tlb_ecc_status_r()                           (0x00500314U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_sa_data_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_sa_data_m()\
				(U32(0x1U) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_fa_data_f(v)\
				((U32(v) & 0x1U) << 2U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_l1tlb_fa_data_m()\
				(U32(0x1U) << 2U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_sa_data_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_sa_data_m()\
				(U32(0x1U) << 1U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_fa_data_f(v)\
				((U32(v) & 0x1U) << 3U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_l1tlb_fa_data_m()\
				(U32(0x1U) << 3U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_total_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 18U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_total_counter_overflow_m()\
				(U32(0x1U) << 18U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_total_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 16U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_total_counter_overflow_m()\
				(U32(0x1U) << 16U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_unique_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 19U)
#define gr_gpc0_mmu_l1tlb_ecc_status_uncorrected_err_unique_counter_overflow_m()\
				(U32(0x1U) << 19U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_unique_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 17U)
#define gr_gpc0_mmu_l1tlb_ecc_status_corrected_err_unique_counter_overflow_m()\
				(U32(0x1U) << 17U)
#define gr_gpc0_mmu_l1tlb_ecc_status_reset_f(v)         ((U32(v) & 0x1U) << 30U)
#define gr_gpc0_mmu_l1tlb_ecc_status_reset_task_f()                (0x40000000U)
#define gr_gpc0_mmu_l1tlb_ecc_address_r()                          (0x00500320U)
#define gr_gpc0_mmu_l1tlb_ecc_address_index_f(v)  ((U32(v) & 0xffffffffU) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_r()              (0x00500318U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_s()                (16U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_m() (U32(0xffffU) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_s()         (16U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_f(v)\
				((U32(v) & 0xffffU) << 16U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_m()\
				(U32(0xffffU) << 16U)
#define gr_gpc0_mmu_l1tlb_ecc_corrected_err_count_unique_total_v(r)\
				(((r) >> 16U) & 0xffffU)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_r()            (0x0050031cU)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_s()              (16U)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_m()\
				(U32(0xffffU) << 0U)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_s()       (16U)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_f(v)\
				((U32(v) & 0xffffU) << 16U)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_m()\
				(U32(0xffffU) << 16U)
#define gr_gpc0_mmu_l1tlb_ecc_uncorrected_err_count_unique_total_v(r)\
				(((r) >> 16U) & 0xffffU)
#define gr_gpc0_gpccs_hww_esr_r()                                  (0x00502c98U)
#define gr_gpc0_gpccs_hww_esr_ecc_corrected_f(v)         ((U32(v) & 0x1U) << 0U)
#define gr_gpc0_gpccs_hww_esr_ecc_corrected_m()                (U32(0x1U) << 0U)
#define gr_gpc0_gpccs_hww_esr_ecc_corrected_pending_f()                   (0x1U)
#define gr_gpc0_gpccs_hww_esr_ecc_uncorrected_f(v)       ((U32(v) & 0x1U) << 1U)
#define gr_gpc0_gpccs_hww_esr_ecc_uncorrected_m()              (U32(0x1U) << 1U)
#define gr_gpc0_gpccs_hww_esr_ecc_uncorrected_pending_f()                 (0x2U)
#define gr_gpccs_falcon_ecc_control_r()                            (0x0050268cU)
#define gr_gpccs_falcon_ecc_control_inject_corrected_err_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_gpccs_falcon_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_gpc0_gpccs_falcon_ecc_status_r()                        (0x00502678U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_imem_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_imem_m() (U32(0x1U) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_imem_pending_f()    (0x1U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_dmem_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_dmem_m() (U32(0x1U) << 1U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_dmem_pending_f()    (0x2U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_imem_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_imem_m()\
				(U32(0x1U) << 4U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_imem_pending_f() (0x10U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_dmem_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_dmem_m()\
				(U32(0x1U) << 5U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_dmem_pending_f() (0x20U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_total_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 10U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_total_counter_overflow_m()\
				(U32(0x1U) << 10U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_total_counter_overflow_pending_f()\
				(0x400U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_total_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 8U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_total_counter_overflow_m()\
				(U32(0x1U) << 8U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_total_counter_overflow_pending_f()\
				(0x100U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 11U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_m()\
				(U32(0x1U) << 11U)
#define gr_gpc0_gpccs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_pending_f()\
				(0x800U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_unique_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 9U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_unique_counter_overflow_m()\
				(U32(0x1U) << 9U)
#define gr_gpc0_gpccs_falcon_ecc_status_corrected_err_unique_counter_overflow_pending_f()\
				(0x200U)
#define gr_gpc0_gpccs_falcon_ecc_status_reset_f(v)      ((U32(v) & 0x1U) << 31U)
#define gr_gpc0_gpccs_falcon_ecc_status_reset_task_f()             (0x80000000U)
#define gr_gpc0_gpccs_falcon_ecc_address_r()                       (0x00502684U)
#define gr_gpc0_gpccs_falcon_ecc_address_index_f(v) ((U32(v) & 0x7fffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_address_row_address_s()                   (20U)
#define gr_gpc0_gpccs_falcon_ecc_address_row_address_f(v)\
				((U32(v) & 0xfffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_address_row_address_m()   (U32(0xfffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_address_row_address_v(r)\
				(((r) >> 0U) & 0xfffffU)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_r()           (0x0050267cU)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_s()             (16U)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_m()\
				(U32(0xffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_s()      (16U)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_f(v)\
				((U32(v) & 0xffffU) << 16U)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_m()\
				(U32(0xffffU) << 16U)
#define gr_gpc0_gpccs_falcon_ecc_corrected_err_count_unique_total_v(r)\
				(((r) >> 16U) & 0xffffU)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_r()         (0x00502680U)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_total_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_total_m()\
				(U32(0xffffU) << 0U)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_s()    (16U)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_f(v)\
				((U32(v) & 0xffffU) << 16U)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_m()\
				(U32(0xffffU) << 16U)
#define gr_gpc0_gpccs_falcon_ecc_uncorrected_err_count_unique_total_v(r)\
				(((r) >> 16U) & 0xffffU)
#define gr_fecs_falcon_ecc_control_r()                             (0x0040968cU)
#define gr_fecs_falcon_ecc_control_inject_corrected_err_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_fecs_falcon_ecc_control_inject_uncorrected_err_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_fecs_falcon_ecc_status_r()                              (0x00409678U)
#define gr_fecs_falcon_ecc_status_corrected_err_imem_f(v)\
				((U32(v) & 0x1U) << 0U)
#define gr_fecs_falcon_ecc_status_corrected_err_imem_m()       (U32(0x1U) << 0U)
#define gr_fecs_falcon_ecc_status_corrected_err_imem_pending_f()          (0x1U)
#define gr_fecs_falcon_ecc_status_corrected_err_dmem_f(v)\
				((U32(v) & 0x1U) << 1U)
#define gr_fecs_falcon_ecc_status_corrected_err_dmem_m()       (U32(0x1U) << 1U)
#define gr_fecs_falcon_ecc_status_corrected_err_dmem_pending_f()          (0x2U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_imem_f(v)\
				((U32(v) & 0x1U) << 4U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_imem_m()     (U32(0x1U) << 4U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_imem_pending_f()       (0x10U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_dmem_f(v)\
				((U32(v) & 0x1U) << 5U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_dmem_m()     (U32(0x1U) << 5U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_dmem_pending_f()       (0x20U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_total_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 10U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_total_counter_overflow_m()\
				(U32(0x1U) << 10U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_total_counter_overflow_pending_f()\
				(0x400U)
#define gr_fecs_falcon_ecc_status_corrected_err_total_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 8U)
#define gr_fecs_falcon_ecc_status_corrected_err_total_counter_overflow_m()\
				(U32(0x1U) << 8U)
#define gr_fecs_falcon_ecc_status_corrected_err_total_counter_overflow_pending_f()\
				(0x100U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 11U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_m()\
				(U32(0x1U) << 11U)
#define gr_fecs_falcon_ecc_status_uncorrected_err_unique_counter_overflow_pending_f()\
				(0x800U)
#define gr_fecs_falcon_ecc_status_corrected_err_unique_counter_overflow_f(v)\
				((U32(v) & 0x1U) << 9U)
#define gr_fecs_falcon_ecc_status_corrected_err_unique_counter_overflow_m()\
				(U32(0x1U) << 9U)
#define gr_fecs_falcon_ecc_status_corrected_err_unique_counter_overflow_pending_f()\
				(0x200U)
#define gr_fecs_falcon_ecc_status_reset_f(v)            ((U32(v) & 0x1U) << 31U)
#define gr_fecs_falcon_ecc_status_reset_task_f()                   (0x80000000U)
#define gr_fecs_falcon_ecc_address_r()                             (0x00409684U)
#define gr_fecs_falcon_ecc_address_index_f(v)       ((U32(v) & 0x7fffffU) << 0U)
#define gr_fecs_falcon_ecc_address_row_address_s()                         (20U)
#define gr_fecs_falcon_ecc_address_row_address_f(v)  ((U32(v) & 0xfffffU) << 0U)
#define gr_fecs_falcon_ecc_address_row_address_m()         (U32(0xfffffU) << 0U)
#define gr_fecs_falcon_ecc_address_row_address_v(r)     (((r) >> 0U) & 0xfffffU)
#define gr_fecs_falcon_ecc_corrected_err_count_r()                 (0x0040967cU)
#define gr_fecs_falcon_ecc_corrected_err_count_total_s()                   (16U)
#define gr_fecs_falcon_ecc_corrected_err_count_total_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_fecs_falcon_ecc_corrected_err_count_total_m()    (U32(0xffffU) << 0U)
#define gr_fecs_falcon_ecc_corrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_fecs_falcon_ecc_corrected_err_count_unique_total_s()            (16U)
#define gr_fecs_falcon_ecc_corrected_err_count_unique_total_f(v)\
				((U32(v) & 0xffffU) << 16U)
#define gr_fecs_falcon_ecc_corrected_err_count_unique_total_m()\
				(U32(0xffffU) << 16U)
#define gr_fecs_falcon_ecc_corrected_err_count_unique_total_v(r)\
				(((r) >> 16U) & 0xffffU)
#define gr_fecs_falcon_ecc_uncorrected_err_count_r()               (0x00409680U)
#define gr_fecs_falcon_ecc_uncorrected_err_count_total_f(v)\
				((U32(v) & 0xffffU) << 0U)
#define gr_fecs_falcon_ecc_uncorrected_err_count_total_m()  (U32(0xffffU) << 0U)
#define gr_fecs_falcon_ecc_uncorrected_err_count_total_v(r)\
				(((r) >> 0U) & 0xffffU)
#define gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_s()          (16U)
#define gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_f(v)\
				((U32(v) & 0xffffU) << 16U)
#define gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_m()\
				(U32(0xffffU) << 16U)
#define gr_fecs_falcon_ecc_uncorrected_err_count_unique_total_v(r)\
				(((r) >> 16U) & 0xffffU)
#define gr_debug_0_r()                                             (0x00400080U)
#define gr_debug_0_scg_force_slow_drain_tpc_m()               (U32(0x1U) << 11U)
#define gr_debug_0_scg_force_slow_drain_tpc_enabled_f()                 (0x800U)
#define gr_debug_0_scg_force_slow_drain_tpc_disabled_f()                  (0x0U)
#define gr_debug_2_r()                                             (0x00400088U)
#define gr_debug_2_gfxp_wfi_timeout_unit_m()                  (U32(0x1U) << 27U)
#define gr_debug_2_gfxp_wfi_timeout_unit_usec_f()                         (0x0U)
#define gr_debug_2_gfxp_wfi_timeout_unit_sysclk_f()                 (0x8000000U)
#endif

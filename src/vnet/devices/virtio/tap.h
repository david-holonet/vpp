/*
 *------------------------------------------------------------------
 * Copyright (c) 2017 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *------------------------------------------------------------------
 */

#ifndef _VNET_DEVICES_VIRTIO_TAP_H_
#define _VNET_DEVICES_VIRTIO_TAP_H_

#ifndef MIN
#define MIN(x,y) (((x)<(y))?(x):(y))
#endif

typedef struct
{
  u8 *name;
  u8 hw_addr_set;
  u8 hw_addr[6];
  u16 rx_ring_sz;
  u16 tx_ring_sz;
  u8 *host_namespace;
  u8 *host_bridge;
  ip4_address_t host_ip4_addr;
  u32 host_ip4_prefix_len;
  ip6_address_t host_ip6_addr;
  u32 host_ip6_prefix_len;
  /* return */
  u32 sw_if_index;
  int rv;
  clib_error_t *error;
} tap_create_if_args_t;

/** TAP interface details struct */
typedef struct
{
  u32 sw_if_index;
  u8 dev_name[64];
} tap_interface_details_t;

void tap_create_if (vlib_main_t * vm, tap_create_if_args_t * args);
int tap_delete_if (vlib_main_t * vm, u32 sw_if_index);
int tap_dump_ifs (tap_interface_details_t ** out_tapids);

#endif /* _VNET_DEVICES_VIRTIO_TAP_H_ */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */

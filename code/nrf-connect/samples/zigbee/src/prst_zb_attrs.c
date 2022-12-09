#include "prst_zb_attrs.h"

#include <zboss_api_addons.h>

#include "prst_zb_endpoint_defs.h"

void prst_zb_attrs_init(struct zb_device_ctx *dev_ctx) {
  dev_ctx->basic_attr.zcl_version = ZB_ZCL_VERSION;
  dev_ctx->basic_attr.power_source = ZB_ZCL_BASIC_POWER_SOURCE_BATTERY;
  ZB_ZCL_SET_STRING_VAL(
      dev_ctx->basic_attr.mf_name,
      PRST_BASIC_MANUF_NAME,
      ZB_ZCL_STRING_CONST_SIZE(PRST_BASIC_MANUF_NAME));

  ZB_ZCL_SET_STRING_VAL(
      dev_ctx->basic_attr.model_id,
      PRST_BASIC_MODEL_ID,
      ZB_ZCL_STRING_CONST_SIZE(PRST_BASIC_MODEL_ID));

  dev_ctx->identify_attr.identify_time =
      ZB_ZCL_IDENTIFY_IDENTIFY_TIME_DEFAULT_VALUE;
}

zb_zcl_status_t prst_zb_set_attr_value(zb_uint16_t cluster_id, zb_uint16_t attr_id, void *data) {
  return zb_zcl_set_attr_val(PRST_ZIGBEE_ENDPOINT,
                             cluster_id,
                             ZB_ZCL_CLUSTER_SERVER_ROLE,
                             attr_id,
                             (zb_uint8_t *)data,
                             ZB_FALSE);
}

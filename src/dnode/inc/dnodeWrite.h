/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TDENGINE_DNODE_WRITE_H
#define TDENGINE_DNODE_WRITE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "taosdef.h"
#include "taosmsg.h"

/*
 * Write data based on dnode, the detail result can be fetched from rsponse
 *   pSubmitMsg: Data to be written
 *   pShellObj:  Used to pass a communication handle
 *   callback:   Pass the write result through a callback function, possibly in a different thread space
 *               rsp: will not be freed by callback function
 */
void dnodeWriteData(SShellSubmitMsg *pMsg, void *pShellObj, void (*callback)(SShellSubmitRspMsg *rsp, void *pShellObj));

/*
 * Check if table already exists
 */
int32_t dnodeCheckTableExist(char *tableId);

/*
 * Create noraml table with specified configuration and open it
 */
int32_t dnodeCreateNormalTable(SCreateNormalTableMsg *table);

/*
 * Create stream table with specified configuration and open it
 */
int32_t dnodeCreateStreamTable(SCreateStreamTableMsg *table);

/*
 * Create child table with specified configuration and open it
 */
int32_t dnodeCreateChildTable(SCreateChildTableMsg *table);

/*
 * Modify normal table configuration information
 *
 */
int32_t dnodeAlterNormalTable(SCreateNormalTableMsg *table);

/*
 * Modify stream table configuration information
 */
int32_t dnodeAlterStreamTable(SCreateStreamTableMsg *table);

/*
 * Modify child table configuration information
 */
int32_t dnodeAlterChildTable(SCreateChildTableMsg *table);

/*
 * Remove all child tables of supertable from local repository
 */
int32_t dnodeDropSuperTable(int vid, int sid, int64_t uid);

/*
 * Remove table from local repository
 */
int32_t dnodeDropTable(int vid, int sid, int64_t uid);

#ifdef __cplusplus
}
#endif

#endif
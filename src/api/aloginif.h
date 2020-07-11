/**
 * This file is part of Hercules.
 * http://herc.ws - http://github.com/HerculesWS/Hercules
 *
 * Copyright (C) 2012-2020 Hercules Dev Team
 * Copyright (C) Athena Dev Teams
 *
 * Hercules is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef API_ALOGINIF_H
#define API_ALOGINIF_H

#include "common/hercules.h"
#include "common/db.h"
#include "common/mmo.h"

struct api_session_data;

/**
 * Defines
 **/
//Interval at which api server updates online listing. [Valaris]
#define CHECK_INTERVAL 3600000
//Interval at which api server sends number of connected users. [Skotlex]
#define UPDATE_INTERVAL 10000

#define ALOGINIF_PACKET_LEN_TABLE_START 0x2810
#define ALOGINIF_PACKET_LEN_TABLE_SIZE 0x8

#define aloginif_char_offline(x) aloginif->char_offline_nsd((x)->status.account_id,(x)->status.char_id)

/*=====================================
* Interface : aloginif.h
* Generated by HerculesInterfaceMaker
* created by Susu
*-------------------------------------*/
struct aloginif_interface {

	/* vars */
	int connected;

	/* */
	int packet_len_table[ALOGINIF_PACKET_LEN_TABLE_SIZE];
	int fd;
	int srvinfo;
	char ip_str[128];
	uint32 ip;
	uint16 port;
	char userid[NAME_LENGTH], passwd[NAME_LENGTH];
	int state;
	/* */
	void (*init) (bool minimal);
	void (*final) (void);
	/* funcs */
	void (*setuserid) (char* id);
	void (*setpasswd) (char* pwd);
	void (*checkdefaultlogin) (void);
	bool (*setip) (const char* ip);
	void (*setport) (uint16 port);
	void (*connect_to_server) (void);
	void (*on_disconnect) (void);
	void (*keepalive) (int fd);
	void (*on_ready) (void);

	int (*parse) (int fd);
	int (*parse_connection_state) (int fd);
	int (*parse_pong) (int fd);
};

#ifdef HERCULES_CORE
void aloginif_defaults(void);
#endif // HERCULES_CORE

HPShared struct aloginif_interface *aloginif;

#endif /* API_ALOGINIF_H */

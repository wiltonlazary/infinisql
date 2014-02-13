/*
 * Copyright (c) 2013 Mark Travis <mtravis15432+src@gmail.com>
 * All rights reserved. No warranty, explicit or implicit, provided.
 *
 * This file is part of InfiniSQL(tm).
 
 * InfiniSQL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * InfiniSQL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with InfiniSQL. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   ObGateway.h
 * @author Mark Travis <mtravis15432+src@gmail.com>
 * @date   Sat Jan 25 08:33:48 2014
 * 
 * @brief  Outbound Gateway actor. Counterpart to IbGateway. Receives messages
 * from actors on current node bound for remote nodes. Sends them over the
 * network to IbGateway.
 */

#ifndef INFINISQLOBGATEWAY_H
#define INFINISQLOBGATEWAY_H

#include "Actor.h"

class ObGateway : public Actor
{
public:
    ObGateway(Actor::identity_s identity);
    void operator()();
    ~ObGateway();
    /** 
     * @brief connect to any new remote IbGateway instances
     *
     */
    void updateRemoteGateways();

    int so_sndbuf;
    char *serstrsmall;
    char *cstrsmall;
    std::vector<int> nodeidToSocket;
};

#endif // INFINISQLOBGATEWAY_H
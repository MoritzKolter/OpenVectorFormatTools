/*
---- Copyright Start ----

This file is part of the OpenVectorFormatTools collection. This collection provides tools to facilitate the usage of the OpenVectorFormat.

Copyright (C) 2022 Digital-Production-Aachen

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

---- Copyright End ----
*/

﻿using System;
using System.Collections.Generic;
using System.Text;

namespace OpenVectorFormat.ILTFileReader.Model
{
    class UserData : ILTFileReader.IUserData
    {
        public UserData(byte[] data, long len, string uid) {
            UID = uid;
            Data = data;
            Len = len;
            
        }
        public byte[] Data
        {
            get;
            set;
        }

        public long Len
        {
            get;
            set;
        }

        public string UID
        {
            get;
            set;
        }
    }
}

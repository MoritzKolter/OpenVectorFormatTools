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

﻿namespace OpenVectorFormat.Plausibility
{
    /// <summary>Overall result status of a check.</summary>
    public enum OverallResult
    {
        /// <summary>All checks succeded.</summary>
        ALLSUCCEDED = 0,

        /// <summary>At least one check failed, only warnings were logged.</summary>
        WARNINGS = 1,

        /// <summary>At least one check failed, errors and warnings were logged.</summary>
        ERRORS = 2,
    }
}

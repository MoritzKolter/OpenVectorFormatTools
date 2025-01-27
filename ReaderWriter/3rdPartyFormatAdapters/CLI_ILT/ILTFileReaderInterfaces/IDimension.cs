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

///////////////////////////////////////////////////////////
//  IDimension.cs
//  Implementation of the Interface IDimension
//  Generated by Enterprise Architect
//  Created on:      09-Mai-2018 16:36:51
//  Original author: Dirks
///////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;



namespace OpenVectorFormat.ILTFileReader {
    /// <summary>
    /// Optional: Describes the dimensions of the outline box which completely contains the part in absolute coordinates (in mm)
    /// with respect to the origin. The conditions x1 &lt x2 , y1 &lt y2 and z1 &lt z2 must be satisfied.
    /// </summary>
    public interface IDimension   {

		float X1{
			get;
		}

		float X2{
			get;
		}

		float Y1{
			get;
		}

		float Y2{
			get;
		}

		float Z1{
			get;
		}

		float Z2{
			get;
		}
	}//end IDimension

}//end namespace OpenVectorFormat.ILTFileReader

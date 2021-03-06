//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		IMDProvider.h
//
//	@doc:
//		Abstract class for retrieving metadata from an external location.
//---------------------------------------------------------------------------



#ifndef GPMD_IMDProvider_H
#define GPMD_IMDProvider_H

#include "gpos/base.h"
#include "gpos/common/CHashMap.h"

#include "gpos/string/CWStringBase.h"
#include "gpos/string/CWStringConst.h"

#include "naucrates/md/IMDId.h"
#include "naucrates/md/IMDType.h"
#include "naucrates/md/IMDFunction.h"

namespace gpmd
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		IMDProvider
	//
	//	@doc:
	//		Abstract class for retrieving metadata from an external location.
	//
	//---------------------------------------------------------------------------
	class IMDProvider : public CRefCount
	{
		protected:

			// return the mdid for the requested type
			static
			IMDId *PmdidTypeGPDB
				(
				IMemoryPool *pmp,
				CSystemId sysid,
				IMDType::ETypeInfo eti
				);

		public:
			virtual ~IMDProvider(){}
			
			// returns the DXL string of the requested metadata object
			virtual 
			CWStringBase *PstrObject(IMemoryPool *pmp, CMDAccessor *pmda, IMDId *pmdid) const = 0;

			// return the mdid for the specified system id and type
			virtual 
			IMDId *Pmdid(IMemoryPool *pmp, CSystemId sysid, IMDType::ETypeInfo eti) const = 0;
	};

	// arrays of MD providers
	typedef CDynamicPtrArray<IMDProvider, CleanupRelease> DrgPmdp;

}



#endif // !GPMD_IMDProvider_H

// EOF

//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2016 Pivotal Software, Inc.
//
//	@filename:
//		CParseHandlerHint.h
//
//	@doc:
//		SAX parse handler class for parsing hint configuration
//---------------------------------------------------------------------------

#ifndef GPDXL_CParseHandlerHint_H
#define GPDXL_CParseHandlerHint_H

#include "gpos/base.h"
#include "naucrates/dxl/parser/CParseHandlerBase.h"
#include "gpopt/engine/CHint.h"

namespace gpdxl
{
	using namespace gpos;

	XERCES_CPP_NAMESPACE_USE

	//---------------------------------------------------------------------------
	//	@class:
	//		CParseHandlerHint
	//
	//	@doc:
	//		SAX parse handler class for parsing hint configuration options
	//
	//---------------------------------------------------------------------------
	class CParseHandlerHint : public CParseHandlerBase
	{
		private:

			// hint configuration
			CHint *m_phint;

			// private copy ctor
			CParseHandlerHint(const CParseHandlerHint&);

			// process the start of an element
			void StartElement
				(
					const XMLCh* const xmlszUri, 		// URI of element's namespace
 					const XMLCh* const xmlszLocalname,	// local part of element's name
					const XMLCh* const xmlszQname,		// element's qname
					const Attributes& attr				// element's attributes
				);

			// process the end of an element
			void EndElement
				(
					const XMLCh* const xmlszUri, 		// URI of element's namespace
					const XMLCh* const xmlszLocalname,	// local part of element's name
					const XMLCh* const xmlszQname		// element's qname
				);

		public:
			// ctor
			CParseHandlerHint
				(
				IMemoryPool *pmp,
				CParseHandlerManager *pphm,
				CParseHandlerBase *pphRoot
				);

			// dtor
			virtual
			~CParseHandlerHint();

			// type of the parse handler
			virtual
			EDxlParseHandlerType Edxlphtype() const;

			// hint configuration
			CHint *Phint() const;
	};
}

#endif // !GPDXL_CParseHandlerHint_H

// EOF

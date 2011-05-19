// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _OpenGl_Error_HeaderFile
#define _OpenGl_Error_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Standard_DefineException_HeaderFile
#include <Standard_DefineException.hxx>
#endif
#ifndef _Standard_SStream_HeaderFile
#include <Standard_SStream.hxx>
#endif

#ifndef _Standard_NumericError_HeaderFile
#include <Standard_NumericError.hxx>
#endif
#ifndef _Handle_OpenGl_Error_HeaderFile
#include <Handle_OpenGl_Error.hxx>
#endif

#if !defined No_Exception && !defined No_OpenGl_Error
#define OpenGl_Error_Raise_if(CONDITION,MESSAGE) \
  if (CONDITION) OpenGl_Error::Raise(MESSAGE);
#else
#define OpenGl_Error_Raise_if(CONDITION,MESSAGE)
#endif

DEFINE_STANDARD_EXCEPTION(OpenGl_Error,Standard_NumericError)

#endif
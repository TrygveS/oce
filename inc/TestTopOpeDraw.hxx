// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TestTopOpeDraw_HeaderFile
#define _TestTopOpeDraw_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

class Draw_Interpretor;
class TestTopOpeDraw_ListOfPnt2d;
class TestTopOpeDraw_DrawableSHA;
class TestTopOpeDraw_DrawableSUR;
class TestTopOpeDraw_DrawableC3D;
class TestTopOpeDraw_DrawableC2D;
class TestTopOpeDraw_DrawableP3D;
class TestTopOpeDraw_Array1OfDrawableP3D;
class TestTopOpeDraw_HArray1OfDrawableP3D;
class TestTopOpeDraw_DrawableP2D;
class TestTopOpeDraw_DrawableMesure;
class TestTopOpeDraw_Array1OfDrawableMesure;
class TestTopOpeDraw_HArray1OfDrawableMesure;
class TestTopOpeDraw_ListNodeOfListOfPnt2d;
class TestTopOpeDraw_ListIteratorOfListOfPnt2d;



class TestTopOpeDraw  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
  Standard_EXPORT   static  void AllCommands(Draw_Interpretor& I) ;
  
  Standard_EXPORT   static  void OtherCommands(Draw_Interpretor& I) ;





protected:





private:




friend class TestTopOpeDraw_ListOfPnt2d;
friend class TestTopOpeDraw_DrawableSHA;
friend class TestTopOpeDraw_DrawableSUR;
friend class TestTopOpeDraw_DrawableC3D;
friend class TestTopOpeDraw_DrawableC2D;
friend class TestTopOpeDraw_DrawableP3D;
friend class TestTopOpeDraw_Array1OfDrawableP3D;
friend class TestTopOpeDraw_HArray1OfDrawableP3D;
friend class TestTopOpeDraw_DrawableP2D;
friend class TestTopOpeDraw_DrawableMesure;
friend class TestTopOpeDraw_Array1OfDrawableMesure;
friend class TestTopOpeDraw_HArray1OfDrawableMesure;
friend class TestTopOpeDraw_ListNodeOfListOfPnt2d;
friend class TestTopOpeDraw_ListIteratorOfListOfPnt2d;

};





// other Inline functions and methods (like "C++: function call" methods)


#endif
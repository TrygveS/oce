//static const char* sccsid = "@(#)Expr_UnaryFunction.cxx	3.2 95/01/10"; // Do not delete this line. Used by sccs.
// Copyright: 	Matra-Datavision 1991
// File:	Expr_UnaryFunction.cxx
// Created:	Tue May 28 14:40:33 1991
// Author:	Arnaud BOUZY
//		<adn>

#ifndef DEB
#define No_Standard_RangeError
#define No_Standard_OutOfRange
#endif

#include <Expr_UnaryFunction.ixx>
#include <Expr_InvalidFunction.hxx>
#include <Expr_Array1OfNamedUnknown.hxx>
#include <Expr_Array1OfGeneralExpression.hxx>
#include <Expr_FunctionDerivative.hxx>
#include <Expr_Product.hxx>
#include <Expr_Operators.hxx>
#include <Expr.hxx>

Expr_UnaryFunction::Expr_UnaryFunction (const Handle(Expr_GeneralFunction)& func, const Handle(Expr_GeneralExpression)& exp)
{
  if (func->NbOfVariables() != 1) {
    Expr_InvalidFunction::Raise();
  }
  myFunction = func;
  CreateOperand(exp);
}

Handle(Expr_GeneralFunction) Expr_UnaryFunction::Function () const
{
  return myFunction;
}

Handle(Expr_GeneralExpression) Expr_UnaryFunction::ShallowSimplified () const
{
  Handle(Expr_GeneralExpression) op = Operand();
  if (op->IsKind(STANDARD_TYPE(Expr_NumericValue))) {
    Handle(Expr_NumericValue) nval = Handle(Expr_NumericValue)::DownCast(op);
    TColStd_Array1OfReal tabval(1,1);
    tabval(1) = nval->GetValue();
    Expr_Array1OfNamedUnknown vars(1,1);
    vars(1) = myFunction->Variable(1);
    Standard_Real res = myFunction->Evaluate(vars,tabval);
    return new Expr_NumericValue(res);
  }
  Handle(Expr_UnaryFunction) me = this;
  return me;
}

Handle(Expr_GeneralExpression) Expr_UnaryFunction::Copy () const
{
  return new Expr_UnaryFunction(myFunction,Expr::CopyShare(Operand()));
}

Standard_Boolean Expr_UnaryFunction::IsIdentical (const Handle(Expr_GeneralExpression)& Other) const
{
  if (!Other->IsKind(STANDARD_TYPE(Expr_UnaryFunction))) {
    return Standard_False;
  }
  Handle(Expr_UnaryFunction) fother = Handle(Expr_UnaryFunction)::DownCast(Other);
  Handle(Expr_GeneralExpression) otherexp = fother->Operand();
  if (otherexp->IsIdentical(Operand())) {
    if (myFunction->IsIdentical(fother->Function())) {
      return Standard_True;
    }
  }
  return Standard_False;
}

Standard_Boolean Expr_UnaryFunction::IsLinear () const
{
  if (!ContainsUnknowns()) {
    return Standard_True;
  }
  if (!Operand()->IsLinear()) {
    return Standard_False;
  }
  return myFunction->IsLinearOnVariable(1);
}

Handle(Expr_GeneralExpression) Expr_UnaryFunction::Derivative (const Handle(Expr_NamedUnknown)& X) const
{
  Handle(Expr_NamedUnknown) myvar = myFunction->Variable(1);
  Handle(Expr_GeneralExpression) myop = Operand();
  Handle(Expr_GeneralExpression) myexpder = myop->Derivative(X);
  Handle(Expr_GeneralFunction) myfuncder = myFunction->Derivative(myvar);
  Handle(Expr_UnaryFunction) firstpart = new Expr_UnaryFunction(myfuncder,Expr::CopyShare(myop));
  Handle(Expr_Product) resu = firstpart->ShallowSimplified() * myexpder;
  return resu->ShallowSimplified();
}

Standard_Real Expr_UnaryFunction::Evaluate(const Expr_Array1OfNamedUnknown& vars, const TColStd_Array1OfReal& vals) const
{
  Expr_Array1OfNamedUnknown varsfunc(1,1);
  varsfunc(1) = myFunction->Variable(1);
  TColStd_Array1OfReal valsfunc(1,1);
  valsfunc(1) = Operand()->Evaluate(vars,vals);
  return myFunction->Evaluate(varsfunc,valsfunc);
}

TCollection_AsciiString Expr_UnaryFunction::String() const
{
  TCollection_AsciiString res = myFunction->GetStringName();
  res += "(";
  res += Operand()->String();
  res += ")";;
  return res;
}
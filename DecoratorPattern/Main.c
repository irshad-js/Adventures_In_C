#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*

Base pizzas are topped up with toppings and final amount is calculated.

Base pizzas are the objects to be decorated

Toppings are decorator objects

Decorator design pattern implementation is thus

*/

#define Regular_Base_Price 2.25
#define Jalapeno_Topping_Price 0.85
#define Cheese_Topping_Price 0.95
#define Tommato_Topping_Price 0.55

typedef struct Base Base;
typedef struct Topping Topping;

struct Base
{  
    double PricingData;
    void (*SetPricingData)(Base * me);
    double (*GetPricingData)(Base * me);
};

struct Topping
{
    double PricingData;
    void (*SetPricingData)(Topping * me);
    double (*GetPricingData)(Topping * me);
};

void SetRegularBasePizzaPricingData(Base * me);
double GetRegularBasePizzaPricingData(Base * me);

void SetCheeseToppingPricingData(Topping * me);
double GetCheeseToppingPricingData(Topping * me);

void SetJalapenoToppingPricingData(Topping * me);
double GetJalapenoToppingPricingData(Topping * me);

void SetTomattoToppingPricingData(Topping * me);
double GetTommatoToppingPricingData(Topping * me);


void SetRegularBasePizzaPricingData(Base * me)
{
    me->PricingData = Regular_Base_Price;
}

double GetRegularBasePizzaPricingData(Base * me)
{
    return me->PricingData;
}

void SetCheeseToppingPricingData(Topping * me)
{
    me->PricingData = Cheese_Topping_Price;
}

double GetCheeseToppingPricingData(Topping * me)
{
    return me->PricingData;
}

void SetJalapenoToppingPricingData(Topping * me)
{
    me->PricingData = Jalapeno_Topping_Price;
}

double GetJalapenoToppingPricingData(Topping * me)
{
    return me->PricingData;
}

void SetTommatoToppingPricingData(Topping * me)
{
    me->PricingData = Tommato_Topping_Price;
}

double GetTommatoToppingPricingData(Topping * me)
{
    return me->PricingData;
}

Base* InitializeBasePizza(Base * const me)
{
    me->SetPricingData(me);
    return me;
}

Base* InitializeTopping(Base * const me, Topping * const this)
{

    if (this->PricingData == 0){
        this->SetPricingData(this);
    }

    me->PricingData = me->PricingData + this->GetPricingData(this);
    return me;
}

int main(){

    Base * Pizza = (Base*)malloc(sizeof(Base));

    Topping * CheeseTopping = (Topping*)malloc(sizeof(Topping));
    Topping * JalapenoTopping = (Topping*)malloc(sizeof(Topping));
    Topping * TommatoTopping = (Topping*)malloc(sizeof(Topping));

    // Install handlers

    Pizza->SetPricingData = SetRegularBasePizzaPricingData;
    CheeseTopping->SetPricingData = SetCheeseToppingPricingData;
    JalapenoTopping->SetPricingData = SetJalapenoToppingPricingData;
    TommatoTopping->SetPricingData = SetTommatoToppingPricingData;

    Pizza->GetPricingData = GetRegularBasePizzaPricingData;
    CheeseTopping->GetPricingData = GetCheeseToppingPricingData;
    JalapenoTopping->GetPricingData = GetJalapenoToppingPricingData;
    TommatoTopping->GetPricingData = GetTommatoToppingPricingData;

    Pizza->SetPricingData(Pizza);
    CheeseTopping->SetPricingData(CheeseTopping);
    JalapenoTopping->SetPricingData(JalapenoTopping);
    TommatoTopping->SetPricingData(TommatoTopping);

    /*

    Pizza = InitializeBasePizza(Pizza);
    Pizza = InitializeTopping(Pizza,CheeseTopping);
    Pizza = InitializeTopping(Pizza,JalapenoTopping);
    Pizza = InitializeTopping(Pizza,TommatoTopping);

    */

    /*

    or 

    Pizza = InitializeTopping(InitializeTopping(InitializeTopping(InitializeBasePizza(Pizza),CheeseTopping),JalapenoTopping),TommatoTopping);
   
    */

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*

Consider a case where different algorithms are necessary and need to be interchangeable. That is where strategy pattern comes handy

A map application can just invoke a router function which can effectively call different algorithms depending upon user input - bike - walk - etc.

Consider an application where discounts are calculated for three different customer cateogories :

Bronze customers: Get 2 % reduction on every item bought.

Silver customers: Get 5 % reduction on every item bought.

Gold customers: Get 10 % off on all items and free shipping

*/

typedef double (*PriceStrategy)(double OrderAmount,double ShippingAmount);

typedef struct Customer Customer;

double BronzePriceStrategy(double amount, double shipping);

double SilverPriceStrategy(double amount, double shipping);

double GoldPriceStrategy(double amount, double shipping);

struct Customer{

    const char * CustomerName;

    const char * CustomerAddress;

    PriceStrategy PricingFunction;

};

Customer CreateCustomer( Customer * const me, const char * CustomerName, const char * CustomerAddress, PriceStrategy PricingFunction );

double BronzePriceStrategy(double amount, double shipping){

    return amount * 0.98 + shipping;

}

double SilverPriceStrategy(double amount, double shipping){

    return amount * 0.95 + shipping;

}

double GoldPriceStrategy(double amount, double shipping){

    /* Free shipping for gold customers. */
    return amount * 0.90;

}


Customer CreateCustomer( Customer * const me, const char * CustomerName, const char * CustomerAddress, PriceStrategy PricingFunction ){

    me->CustomerAddress = CustomerAddress;

    me->CustomerName = CustomerName;

    me->PricingFunction = PricingFunction;

}

int main(){

    #define Amount 750

    #define Shipping 250

    Customer BronzeCustomer, GoldCustomer, SilverCustomer;

    printf("\nStrategy Pattern Implemenation in C");

    CreateCustomer(&BronzeCustomer,"BronzeSales","Denmark",BronzePriceStrategy);

    CreateCustomer(&GoldCustomer,"GoldSales","Germany",GoldPriceStrategy);
    
    CreateCustomer(&SilverCustomer,"SilverSales","Netherlands",SilverPriceStrategy);
    
    printf("\nCustomers created\n");

    double Order1,Order2,Order3;

    Order1 = BronzeCustomer.PricingFunction(Amount,Shipping);

    Order2 = SilverCustomer.PricingFunction(Amount,Shipping);

    Order3 = GoldCustomer.PricingFunction(Amount,Shipping);

    printf("\nFor same order value and Shipping value, Gold -> %lf, Silver -> %lf and Bronze -> %lf",Order3,Order2,Order1);

    return 0;
}

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>
#include <iostream>

// AUFGABE 1.8
int gcd(int a, int b){
  int divisor = a;
  if (a > b) {
    divisor = b;
  }
  while (!(a%divisor == 0 && b%divisor == 0) && divisor >= 2) {
    divisor -= 1;
  }
  return divisor;
}

// AUFGABE 1.9
int checksum(int number){
  int result = 0;
  if (number < 0) {
    number *= (-1);
  }
  while(number/10 > 0){
    result += number%10;
    number /= 10;
  }
  result += number%10;
  return result;
}

// AUFGABE 1.10
int sum_multiples(int limit){
  int result = 0;
  for (int i = 1; i <= limit; ++i)
  {
    if ((i%3 == 0) || (i%5 == 0))
    {
      result += i;
    }
  }
  return result;
}

// AUFGABE 1.11
double fract(double number){
  int intpart = (int) number;
  return number - intpart;
}

// AUFGABE 1.12
float calc_volume(float radius, float height){
  return M_PI*std::pow(radius, 2)*height;
}

float calc_surface(float radius, float height){
  return (2*M_PI*std::pow(radius, 2))+(2*M_PI*radius*height);
}

// AUFGABE 1.13
int factorial(int number)
{
  if (number <= 1) {
    return 0;
  }
  int result = 1;
  for (int i = 1; i <= number; ++i) {
    result *= i;
  }
  return result;
}


// AUFGABE 1.14
bool is_prime(int number) 
{
  if (number <= 1) {
    return false;
  }
  for (int i = 2; i < number/2; ++i) {
      if(number%i == 0) {
          return false;
      }
  }
  return true;
}


TEST_CASE("describe_gcd", "[gcd]")
{
  REQUIRE(gcd(2,4) == 2);
  REQUIRE(gcd(9,6) == 3);
  REQUIRE(gcd(3,7) == 1);
}

TEST_CASE("describe_checksum", "[checksum]")
{
  REQUIRE(checksum(-2048) == 14);
  REQUIRE(checksum(489236) == 32);
  REQUIRE(checksum(121682) == 20);
}

TEST_CASE("describe_sum_multiples", "[sum_multiples]")
{
  REQUIRE(sum_multiples(1000) == 234168);
  REQUIRE(sum_multiples(11) == 33);
  REQUIRE(sum_multiples(2) == 0);
}

TEST_CASE("describe_fract", "[fract]")
{
  REQUIRE(fract(1.23456) == Approx(0.23456));
  REQUIRE(fract(935.0548) == Approx(0.0548));
  REQUIRE(fract(-19.993) == Approx(-0.993));
}

TEST_CASE("Test calc_volume", "[calc_volume]")
{
  REQUIRE(calc_volume(3, 4) == Approx(113.097));
  REQUIRE(calc_volume(7, 9) == Approx(1385.442));
  REQUIRE(calc_volume(0.5, 5.3) == Approx(4.16261));
}

TEST_CASE("Test calc_surface", "[calc_surface]")
{
  REQUIRE(calc_surface(3, 7) == Approx(188.4955));
  REQUIRE(calc_surface(6, 12) == Approx(678.584));
  REQUIRE(calc_surface(2.25, 10) == Approx(173.180));
}


TEST_CASE("factorial test", "[factorial]")
{
  REQUIRE(factorial(5) == 120);
  REQUIRE(factorial(4) == 24);
  REQUIRE(factorial(-2) == 0);
}


TEST_CASE("describe_is_prime", "[is_prime]")
{
  REQUIRE(is_prime(0) == false);
  REQUIRE(is_prime(47) == true);
  REQUIRE(is_prime(255) == false);
}


int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}

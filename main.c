#include <stdio.h>
#include <stdlib.h>

int main()
{
  // declare and initialise variables
  int menu = 0;
  int menu2 = 0;
  int quit = 0;
  int consumption = 0;
  float price = 0;
  float fresh = 0;
  float waste = 0;
  float stand = 0;
  int consumption2 = 0;
  float price2 = 0;
  float fresh2 = 0;
  float waste2 = 0;
  float stand2 = 0;
  float vat = 0;
  float price3 = 0;
  float cost = 0;
  // track total water consumption by type
  int totconsumption = 0;
  int domconsumption = 0;
  int comconsumption = 0;
  // track total revenue
  float rev = 0;
  // track bill prices by type
  float maxdom = 0;
  float maxcom = 0;
  float totdom = 0;
  float totcom = 0;
  // track number of bills entered
  int countdom = 0;
  int countcom = 0;

  // display menu
  printf ("\n");
  printf ("1. Calculate and view a water bill\n");
  printf ("2. View quarterly sums and statistics\n");
  printf ("3. Quit\n");
  printf ("\n");
  printf ("Enter the corresponding number for what you want to do: ");
  scanf ("%i", &menu);

  // display menu until quit is selected
  while (menu != 3)
  {
    printf ("\n");

    // parse inputted command
    if (menu < 1 || menu > 3)
    {
      printf ("Enter a valid command number.\n");
    }
    else
    {
      // calculate water bill
      if (menu == 1)
      {
        // set 'quit' to 0 in case a bill has been calcualted previously
        quit = 0;
        printf ("What type of customer is the bill being calculated for?\n");
        printf ("\n");
        printf ("1. Domestic\n");
        printf ("2. Commercial\n");
        printf ("\n");
        printf ("Enter the corresponding number for what you want to do: ");
        scanf ("%i", &menu2);

        // display customer type menu until a valid command is input
        while (quit != 1)
        {
          printf ("\n");

          // parse inputted command
          if (menu2 < 1 || menu2 > 2)
          {
            printf ("Enter a valid command number.\n");
          }
          else
          {
            // calculate domestic water bill
            if (menu2 == 1)
            {
              printf ("Enter the number of cubic metres of water the customer has consumed this quarter: ");
              scanf ("%i", &consumption);

              // keep asking for water consumed until it's input
              while (quit != 1)
              {
                printf ("\n");

                if (consumption < 0)
                {
                  printf ("Enter a positive integer.\n");
                }
                else
                {
                  countdom += 1;
                  totconsumption += consumption;
                  domconsumption += consumption;
                  // set 'fresh' to 0 in case a domestic bill has been calculated previously
                  fresh = 0;

                  // calculate band 5 tariff
                  if (consumption > 40)
                  {
                    fresh = fresh + ((consumption - 40) * 2.5) + 21.2;
                  }

                  // calculate band 4 tariff
                  if (consumption > 25 && consumption < 41)
                  {
                    fresh = fresh + ((consumption - 25) * 0.75) + 9.95;
                  }

                  // calculate band 3 tariff
                  if (consumption > 12 && consumption < 26)
                  {
                    fresh = fresh + ((consumption - 12) * 0.5) + 3.45;
                  }

                  // calculate band 2 tariff
                  if (consumption > 5 && consumption < 13)
                  {
                    fresh = fresh + ((consumption - 5) * 0.35) + 1;
                  }

                  // calculate band 1 tariff
                  if (consumption > -1 && consumption < 6)
                  {
                    fresh = fresh + (consumption * 0.2);
                  }

                  // calculate domestic fixed charges and update statistics
                  waste = (consumption * 0.95) * 0.25;
                  stand = 91 * 0.1;
                  price = fresh + waste + 10 + stand;
                  rev += price;
                  totdom += price;

                  // update maximum domestic bill
                  if (price > maxdom)
                  {
                    maxdom = price;
                  }

                  // display bill
                  printf ("----------------------------------------------------\n");
                  printf ("Customer type: Domestic\n");
                  printf ("Water consumption this quarter in cubic metres: %i\n", consumption);
                  printf ("Price for fresh water: £%.2f\n", fresh);
                  printf ("Price for waste water: £%.2f\n", waste);
                  printf ("Price for surface water: £10\n");
                  printf ("Standing charge: £%.2f\n", stand);
                  printf ("Total: £%.2f.\n", price);
                  printf ("----------------------------------------------------\n");

                  // signal that domestic bill calculation has finished
                  quit = 1;
                  
                  break;
                }

                // display water consumption menu again if needed
                printf ("\n");
                printf ("Enter the number of cubic metres of water the customer has consumed this quarter: ");
                scanf ("%i", &consumption);

                printf ("\n");
              }
            }
            // calculate commercial water bill
            else if (menu2 == 2)
            {
              printf ("Enter the number of cubic metres of water the customer has consumed this quarter: ");
              scanf ("%i", &consumption2);

              // keep asking for water consumed until it's input
              while (quit != 1)
              {
                printf ("\n");

                if (consumption2 < 0)
                {
                  printf ("Enter a positive integer.\n");
                }
                else
                {
                  countcom += 1;
                  totconsumption += consumption2;
                  comconsumption += consumption2;
                  // calculates only band 5 tariff
                  fresh2 = consumption2 * 2.5;

                  // calculate commercial fixed charges and update statistics
                  waste2 = (consumption2 * 0.95) * 2;
                  stand2 = 91 * 1.3;
                  price2 = fresh2 + waste2 + 50 + stand2;
                  rev += price2;
                  
                  // calculate VAT of bill and calculate final bill
                  vat = (price2 * 1.2) - price2;
                  price3 = price2 * 1.2;
                  totcom += price3;

                  // update maximum commercial bill
                  if (price3 > maxcom)
                  {
                    maxcom = price3;
                  }

                  // display bill
                  printf ("----------------------------------------------------\n");
                  printf ("Customer type: Commercial\n");
                  printf ("Water consumption this quarter in cubic metres: %i\n", consumption2);
                  printf ("Price for fresh water: £%.2f\n", fresh2);
                  printf ("Price for waste water: £%.2f\n", waste2);
                  printf ("Price for surface water: £50\n");
                  printf ("Standing charge: £%.2f\n", stand2);
                  printf ("VAT: £%.2f\n", vat);
                  printf ("Total: £%.2f.\n", price3);
                  printf ("----------------------------------------------------\n");

                  // signal that commercial bill calculation has finished
                  quit = 1;
                  
                  break;
                }

                // display water consumption menu again if needed
                printf ("\n");
                printf ("Enter the number of cubic metres of water the customer has consumed this quarter: ");
                scanf ("%i", &consumption2);

                printf ("\n");
              }
            }

            // stop displaying menu for calculating water bills
            if (quit == 1)
              break;
          }

          // display customer type menu again if needed
          printf ("\n");
          printf ("What type of customer is the bill being calculated for?\n");
          printf ("\n");
          printf ("1. Domestic\n");
          printf ("2. Commercial\n");
          printf ("\n");
          printf ("Enter the corresponding number for what you want to do: ");
          scanf ("%i", &menu2);
        }
      }
      // view quartlerly sums and statistics
      else
      {
        if (menu == 2)
        {
          // calculate and display quarterly sums and statistics
          if (price == 0 && price3 == 0)
          {
            printf ("There are no statistics to display since no bills have been calculated.\n");
          }
          else
          {
            cost = totconsumption;

            printf ("--------------------------------------------------------\n");
            printf ("Total amount of fresh water consumed by all customers in cubic metres: %i\n", totconsumption);
            printf ("Total amount of fresh water consumed by domestic customers in cubic metres: %i\n", domconsumption);
            printf ("Total amount of fresh water consumed by commercial customers in cubic metres: %i\n", comconsumption);
            printf ("Total amount of revenue from all bills: £%.2f\n", rev);
            printf ("Total cost of providing water to customers: £%.2f\n", cost);
            printf ("Total profit: £%.2f\n", rev-cost);
            printf ("Total income tax to pay: £%.2f\n", (rev-cost)*0.25);
            printf ("Average domestic consumer bill: £%.2f\n", totdom/countdom);
            printf ("Maximum domestic consumer bill: £%.2f\n", maxdom);
            printf ("Average commercial consumer bill: £%.2f\n", totcom/countcom);
            printf ("Maximum commercial consumer bill: £%.2f\n", maxcom);
            printf ("--------------------------------------------------------\n");
          }
        }
      }
    }

    // display command menu again if needed
    printf ("\n");
    printf ("1. Calculate and view a water bill\n");
    printf ("2. View quarterly sums and statistics\n");
    printf ("3. Quit\n");
    printf ("\n");
    printf ("Enter the corresponding number for what you want to do: ");
    scanf ("%i", &menu);
  }

  // quit program
  printf ("\n");
  printf ("You have quit the program.\n");
  printf ("\n");

  return 0;

  exit(0);
}

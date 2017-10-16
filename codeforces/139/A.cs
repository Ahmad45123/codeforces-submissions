using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int pagesTotal = int.Parse(Console.ReadLine());
            int[] pagesPerDay = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

            int currentDay = 0;
            while (pagesTotal > 0)
            {
                currentDay++;
                if (currentDay == 8)
                    currentDay = 1;

                pagesTotal -= pagesPerDay[currentDay - 1];
            }

            Console.WriteLine(currentDay);
            Console.Read();
        }
    }
}
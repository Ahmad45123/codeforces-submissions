using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int friendsNumber = int.Parse(Console.ReadLine()) + 1;
            int peoples = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x)).Sum();

            int ways = 0;
            for (int i = 1; i <= 5; i++)
            {
                if ((peoples + i) % friendsNumber == 1)
                {
                    continue;
                }
                ways++;
            }

            Console.WriteLine(ways);
            Console.Read();
        }
    }
}
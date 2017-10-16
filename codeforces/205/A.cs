using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine(); //Towns number
            int[] towns = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            var townsSorted = new int[towns.Length];
            towns.CopyTo(townsSorted, 0);
            Array.Sort(townsSorted);
            var townsList = towns.ToList();

            if(townsSorted.Length == 1)
                Console.WriteLine("1");
            else if(townsSorted[0] == townsSorted[1])
                Console.WriteLine("Still Rozdil");
            else
                Console.WriteLine(townsList.IndexOf(townsSorted[0]) + 1);
        }
    }
}
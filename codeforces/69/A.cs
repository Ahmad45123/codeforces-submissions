using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            //int testCases = int.Parse(Console.ReadLine());
            //for (int j = 0; j < testCases; j++)
            //{
                int numberOfItems = int.Parse(Console.ReadLine());
                int X = 0, Y = 0, Z = 0;
                for (int i = 0; i < numberOfItems; i++)
                {
                    int[] coord = Array.ConvertAll(Console.ReadLine().Split(' '), input => int.Parse(input));
                    X += coord[0];
                    Y += coord[1];
                    Z += coord[2];
                }

                if(X == 0 && Y == 0 && Z == 0)
                    Console.WriteLine("YES");
                else
                    Console.WriteLine("NO");
            //}
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int entries = int.Parse(Console.ReadLine());
            int[][] points = new int[entries][];

            //Get data
            for (int i = 0; i < entries; i++)
            {
                points[i] = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            }

            int result = 0;

            //For all
            for (int i = 0; i < entries; i++)
            {
                bool hasUpper = false;
                bool hasBottom = false;
                bool hasLeft = false;
                bool hasRight = false;

                for (int j = 0; j < entries; j++)
                {
                    if (points[i][0] > points[j][0] && points[i][1] == points[j][1])
                    {
                        hasRight = true;
                    }
                    else if (points[i][0] < points[j][0] && points[i][1] == points[j][1])
                    {
                        hasLeft = true;
                    }
                    else if (points[i][0] == points[j][0] && points[i][1] < points[j][1])
                    {
                        hasBottom = true;
                    }
                    else if (points[i][0] == points[j][0] && points[i][1] > points[j][1])
                    {
                        hasUpper = true;
                    }
                }

                if (hasRight && hasLeft && hasUpper && hasBottom)
                {
                    result++;
                }
            }

            Console.WriteLine(result);
            Console.Read();
        }
    }
}
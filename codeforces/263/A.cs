using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            //Get one position.
            int oneX = 0;
            int oneY = 0;
            for (int i = 0; i < 5; i++)
            {
                int[] values = Array.ConvertAll(Console.ReadLine().Split(' '), input => int.Parse(input));
                for (int j = 0; j < 5; j++)
                {
                    if (values[j] == 1)
                    {
                        oneX = i;
                        oneY = j;
                    }
                }
            }

            //Get road to middle.
            int X = Math.Abs(oneX - 2);
            int Y = Math.Abs(oneY - 2);

            Console.WriteLine(X + Y);
        }
    }
}

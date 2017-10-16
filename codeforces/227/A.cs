using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] start = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            int[] pos = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            int[] end = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));

            double r = findSide(start[0], start[1], pos[0], pos[1], end[0], end[1]);

            if(r == 0)
                    Console.WriteLine("TOWARDS");
            else if(r < 0)
                    Console.WriteLine("RIGHT");
            else if(r > 0)
                    Console.WriteLine("LEFT");
        }

        public static double findSide(
            double ax, double ay,
            double bx, double by,
            double cx, double cy)
        {
            return ((bx - ax) * (cy - ay) - (by - ay) * (cx - ax));
        }
    }
}
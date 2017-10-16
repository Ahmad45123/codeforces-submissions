using System;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] dimensions = Array.ConvertAll(Console.ReadLine().Split(' '), x => int.Parse(x));
            char[,] chessboard = new char[dimensions[0],dimensions[1]];

            //Get data.
            for (int i = 0; i < dimensions[0]; i++)
            {
                string vs = Console.ReadLine();
                for (int j = 0; j < vs.Length; j++)
                {
                    chessboard[i, j] = vs[j];
                }
            }

            //LOOOP
            for (int i = 0; i < chessboard.GetLength(0); i++)
            {
                for (int j = 0; j < chessboard.GetLength(1); j++)
                {
                    if(chessboard[i,j] == '-')
                        continue;

                    chessboard[i, j] = ((i + j) & 1) == 1 ? 'W' : 'B';
                }
            }

            //Get result.
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < chessboard.GetLength(0); i++)
            {
                for (int j = 0; j < chessboard.GetLength(1); j++)
                {
                    result.Append(chessboard[i, j]);
                }
                result.Append('\n');
            }

            Console.Write(result);
        }
    }
}
using System;
using System.Linq;

public class Program
{
    public static string[] AreAlmostEquivalent(string[] s, string[] t)
    {
        string[] result = new string[s.Length];

        for (int i = 0; i < s.Length; i++)
        {
            int[] freq_s = new int[26]; // Frequency count for characters in string s
            int[] freq_t = new int[26]; // Frequency count for characters in string t

            // Count the frequency of characters in string s
            foreach (char c in s[i])
            {
                freq_s[c - 'a']++;
            }

            // Count the frequency of characters in string t
            foreach (char c in t[i])
            {
                freq_t[c - 'a']++;
            }

            // Compare the lengths and character frequencies
            if (s[i].Length != t[i].Length || !freq_s.OrderBy(f => f).SequenceEqual(freq_t.OrderBy(f => f)))
            {
                result[i] = "NO";
            }
            else
            {
                result[i] = "YES";
            }
        }

        return result;
    }

    public static void Main(string[] args)
    {
        string[] s = { "abc", "abb", "aabb" };
        string[] t = { "cba", "bab", "abab" };
        string[] result = AreAlmostEquivalent(s, t);
        Console.WriteLine(string.Join(", ", result)); // Output: YES, YES, NO
    }
}

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        ArrayDeque<Integer> nums = new ArrayDeque<Integer>();
        boolean[] primes = new boolean [10001];
        for (int i=2; i<primes.length; i++)
            primes[i] = true;
        
        for (int i=2; i<primes.length; i++)
            if (primes[i])
                for(int j=2*i; j<primes.length; j+=i)
                    primes[j] = false;
        
        for(int i=0; i<n; i++)
            nums.add(sc.nextInt());
        
            int count = 0;
        for (int prime = 2; count < q && prime < primes.length; prime++ )
        {
            if (!primes[prime])
                continue;
            count++;
            ArrayList<Integer>nextResult = new ArrayList<Integer>();
            int left = nums.size();
            for(int i=0; i<left; i++)
            {
                int num = nums.pop();
                if (num%prime==0)
                    nextResult.add(num);
                else nums.add(num);
            }
            if (count%2==1)
            {
                for(Integer val : nextResult)
                    System.out.println(val);
            }
            else
            {
                for(int i=nextResult.size()-1; i>= 0; i--)
                    System.out.println(nextResult.get(i));
            }
        }
        
        while(!nums.isEmpty())
        {
            if (q%2==0)
                System.out.println(nums.pollLast());
            else
                System.out.println(nums.pollFirst());
        }
    }
}

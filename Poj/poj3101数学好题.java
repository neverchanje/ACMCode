/**
 * Created by neverchanje on 15/3/1.
 */

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int n;
    static final int maxn = 1005;
    static int t[] = new int[maxn];

    static int gcd(int a, int b)
    {
        if(b==0) return a;
        return gcd(b, a%b);
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        for(int i=0; i<n; i++)
            t[i] = in.nextInt();

        Arrays.sort(t, 0, n);
        int cnt = 1;
        for(int i=1; i<n; i++) {
            if (t[i] != t[i - 1])
                t[cnt++] = t[i];
        }

        BigInteger xa=null, xb=null, va, vb, g;

        for(int i=1; i<cnt; i++) {
            va = BigInteger.valueOf(t[i]*t[0]);
            vb = BigInteger.valueOf((t[i] - t[0])*2);
            g = va.gcd(vb);
            va = va.divide(g);
            vb = vb.divide(g);
            if(i==1)
            {
                xa = va; xb = vb;
                continue;
            }
            xa = xa.multiply(va).divide(xa.gcd(va));
            xb = xb.gcd(vb);
        }

        System.out.println(xa+" "+xb);
    }
}

/*

 */
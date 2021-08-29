
/**/

        int digit = 1;
        long start = 1;
        long count = digit * num;
        while (n > count)
        {
            n -= count;
            digit++;
            start *= 10;
            count = digit * 9 * start;
        }

        int result = n / digit;
        int remainder = n % digit;

        if (remainder != 0) {
            n = start + result;
        }
        else {
            n = start + result - 1;
            remainder = digit;
        }

        for (int i = remainder; i < digit; ++i) {
            n /= 10;
        }
        
        return n%10;  
    }
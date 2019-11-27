class Gagyi
{
    public static void main (String[]args)
    {
        //Mind a két integert a poolból vesszük ki, így a while nem fut le.
        Integer x = 110;
        Integer t = 110;
        System.out.println (x);
        System.out.println (t);
        while (x <= t && x >= t && t != x);
       
        //A két integert a poolon kívülröl vesszük(-128tól 127ig) így a végtelen ciklus bekövetkezik
        x = 130;
        t = 130;
        System.out.println (x);
        System.out.println (t);
        while (x <= t && x >= t && t != x);
     
        //Bár az integerek a poolon belül vannak a 'new ' kulcsszóval új példányokat hozunk létre.
        /*
        x = new Integer(110);
        t = new Integer(110);
        System.out.println (x);
        System.out.println (t);
        while (x <= t && x >= t && t != x);
        */
        /*
        public static Integer valueOf(int i) {
        if (i >= IntegerCache.low && i <= IntegerCache.high)
        return IntegerCache.cache[i + (-IntegerCache.low)];
        return new Integer(i);
        }
        */
    
    }
}
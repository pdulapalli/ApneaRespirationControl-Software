#include "Globals.h"

void delay_nops(int numNops){
    int i;
    for(i = 0; i < numNops; i++){
        nop();
    }
}

void delay_ms(int numMillis){
    int i;
    for(i = 0; i < numMillis; i++){
        delay_nops(NOP_PER_MS);
    }
}

void delay_50ms(int num50Millis){
    int i;
    for(i = 0; i < num50Millis; i++){
        delay_nops(NOP_PER_50_MS);
    }
}

double testSampleRate = 2; //in Hz

const rom double testWaveform[] = {5,4.6194,3.5355,1.9134,3.0616e-16,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-9.1849e-16,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.5308e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-2.1431e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,2.7555e-15,-1.9134,-3.5355,-4.6194,
-5,-4.6194,-3.5355,-1.9134,-1.225e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-4.9017e-15,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.3474e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
-3.677e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.4699e-14,1.9134,3.5355,4.6194,5,4.6194,
3.5355,1.9134,-2.4524e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.5924e-14,1.9134,3.5355,
4.6194,5,4.6194,3.5355,1.9134,-1.2277e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.7148e-14,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-3.0949e-18,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-1.8373e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.2216e-15,-1.9134,-3.5355,-4.6194,
-5,-4.6194,-3.5355,-1.9134,-1.9597e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,2.4462e-15,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.0822e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
3.9198e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.2047e-14,1.9134,3.5355,4.6194,5,
4.6194,3.5355,1.9134,4.8955e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,1.2256e-14,1.9134,
3.5355,4.6194,5,4.6194,3.5355,1.9134,4.1647e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,
-2.4496e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,7.3448e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,
-3.5355,-1.9134,9.8065e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,4.4097e-14,-1.9134,-3.5355,-4.6194,
-5,-4.6194,-3.5355,-1.9134,-2.6945e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,9.7941e-15,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,7.3572e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,4.6546e-14,
-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.9395e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
1.2243e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,4.9079e-15,1.9134,3.5355,4.6194,5,4.6194,
3.5355,1.9134,4.8995e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-3.1844e-14,1.9134,3.5355,
4.6194,5,4.6194,3.5355,1.9134,1.4693e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,2.4586e-15,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,5.1444e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,3.6761e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.7142e-14,-1.9134,-3.5355,-4.6194,-5,
-4.6194,-3.5355,-1.9134,-7.1045e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-1.7161e-14,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-3.6742e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
9.0646e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.44e-15,1.9134,3.5355,4.6194,5,4.6194,
3.5355,1.9134,5.6343e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,3.1862e-14,1.9134,3.5355,
4.6194,5,1,0.92388,0.70711,0.38268,6.1232e-17,-0.38268,-0.70711,-0.92388,-1,-0.92388,-0.70711,-0.38268,
-1.837e-16,0.38268,0.70711,0.92388,1,0.92388,0.70711,0.38268,3.0616e-16,-0.38268,-0.70711,-0.92388,
-1,-0.92388,-0.70711,-0.38268,-4.2863e-16,0.38268,0.70711,0.92388,1,5,4.6194,3.5355,1.9134,3.0616e-16,
-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-9.1849e-16,1.9134,3.5355,4.6194,5,4.6194,3.5355,
1.9134,1.5308e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.1431e-15,1.9134,3.5355,4.6194,
5,4.6194,3.5355,1.9134,2.7555e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.225e-14,1.9134,
3.5355,4.6194,5,4.6194,3.5355,1.9134,-4.9017e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,
-1.3474e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-3.677e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,
-3.5355,-1.9134,-1.4699e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-2.4524e-15,-1.9134,-3.5355,
-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.5924e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-1.2277e-15,
-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.7148e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,
1.9134,-3.0949e-18,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.8373e-14,1.9134,3.5355,
4.6194,5,4.6194,3.5355,1.9134,1.2216e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.9597e-14,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,2.4462e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-2.0822e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,3.9198e-14,-1.9134,-3.5355,-4.6194,
-5,-4.6194,-3.5355,-1.9134,-2.2047e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,4.8955e-15,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,1.2256e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
4.1647e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.4496e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,
1.9134,7.3448e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,9.8065e-15,1.9134,3.5355,4.6194,5,4.6194,
3.5355,1.9134,4.4097e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.6945e-14,1.9134,3.5355,4.6194,
5,4.6194,3.5355,1.9134,9.7941e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,7.3572e-15,1.9134,3.5355,
4.6194,5,4.6194,3.5355,1.9134,4.6546e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.9395e-14,1.9134,
3.5355,4.6194,5,4.6194,3.5355,1.9134,1.2243e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,4.9079e-15,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,4.8995e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,
-3.1844e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.4693e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,2.4586e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,5.1444e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,
-3.5355,-1.9134,3.6761e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.7142e-14,-1.9134,-3.5355,-4.6194,-5,
-4.6194,-3.5355,-1.9134,-7.1045e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-1.7161e-14,-1.9134,-3.5355,
-4.6194,-5,-4.6194,-3.5355,-1.9134,-3.6742e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,9.0646e-14,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.44e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,5.6343e-14,
-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,3.1862e-14,1.9134,3.5355,4.6194,5,1,0.92388,0.70711,0.38268,
6.1232e-17,-0.38268,-0.70711,-0.92388,-1,-0.92388,-0.70711,-0.38268,-1.837e-16,0.38268,0.70711,0.92388,1,
0.92388,0.70711,0.38268,3.0616e-16,-0.38268,-0.70711,-0.92388,-1,-0.92388,-0.70711,-0.38268,-4.2863e-16,
0.38268,0.70711,0.92388,1,5,4.6194,3.5355,1.9134,3.0616e-16,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-9.1849e-16,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.5308e-15,-1.9134,-3.5355,-4.6194,-5,
-4.6194,-3.5355,-1.9134,-2.1431e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,2.7555e-15,-1.9134,-3.5355,
-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.225e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-4.9017e-15,
-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.3474e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,
1.9134,-3.677e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.4699e-14,1.9134,3.5355,4.6194,
5,4.6194,3.5355,1.9134,-2.4524e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.5924e-14,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-1.2277e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-1.7148e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-3.0949e-18,-1.9134,-3.5355,-4.6194,
-5,-4.6194,-3.5355,-1.9134,-1.8373e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.2216e-15,-1.9134,
-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-1.9597e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
2.4462e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.0822e-14,1.9134,3.5355,4.6194,5,4.6194,
3.5355,1.9134,3.9198e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.2047e-14,1.9134,3.5355,
4.6194,5,4.6194,3.5355,1.9134,4.8955e-15,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,1.2256e-14,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,4.1647e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-2.4496e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,7.3448e-15,-1.9134,-3.5355,-4.6194,-5,
-4.6194,-3.5355,-1.9134,9.8065e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,4.4097e-14,-1.9134,-3.5355,
-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.6945e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,9.7941e-15,
-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,7.3572e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,
4.6546e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-2.9395e-14,1.9134,3.5355,4.6194,5,4.6194,
3.5355,1.9134,1.2243e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,4.9079e-15,1.9134,3.5355,4.6194,
5,4.6194,3.5355,1.9134,4.8995e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,-3.1844e-14,1.9134,
3.5355,4.6194,5,4.6194,3.5355,1.9134,1.4693e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,2.4586e-15,
1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,5.1444e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,-1.9134,
3.6761e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,1.7142e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,-3.5355,
-1.9134,-7.1045e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,-1.7161e-14,-1.9134,-3.5355,-4.6194,-5,-4.6194,
-3.5355,-1.9134,-3.6742e-14,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,9.0646e-14,-1.9134,-3.5355,-4.6194,-5,
-4.6194,-3.5355,-1.9134,-2.44e-15,1.9134,3.5355,4.6194,5,4.6194,3.5355,1.9134,5.6343e-14,-1.9134,-3.5355,
-4.6194,-5,-4.6194,-3.5355,-1.9134,3.1862e-14,1.9134,3.5355,4.6194,5,9001};


/*
const rom double testWaveform[] = {5,3.5355,3.0616e-16,-3.5355,-5,-3.5355,-9.1849e-16,3.5355,
5,3.5355,1.5308e-15,-3.5355,-5,-3.5355,-2.1431e-15,3.5355,5,3.5355,2.7555e-15,-3.5355,-5,
-3.5355,-1.225e-14,3.5355,5,3.5355,-4.9017e-15,-3.5355,-5,-3.5355,-1.3474e-14,3.5355,5,
3.5355,-3.677e-15,-3.5355,-5,-3.5355,-1.4699e-14,3.5355,5,3.5355,-2.4524e-15,-3.5355,-5,
-3.5355,-1.5924e-14,3.5355,5,3.5355,-1.2277e-15,-3.5355,-5,-3.5355,-1.7148e-14,3.5355,5,
3.5355,-3.0949e-18,-3.5355,-5,-3.5355,-1.8373e-14,3.5355,5,3.5355,1.2216e-15,-3.5355,-5,
-3.5355,-1.9597e-14,3.5355,5,3.5355,2.4462e-15,-3.5355,-5,-3.5355,-2.0822e-14,3.5355,5,
3.5355,3.9198e-14,-3.5355,-5,-3.5355,-2.2047e-14,3.5355,5,3.5355,4.8955e-15,-3.5355,-5,
-3.5355,1.2256e-14,3.5355,5,3.5355,4.1647e-14,-3.5355,-5,-3.5355,-2.4496e-14,3.5355,5,
3.5355,7.3448e-15,-3.5355,-5,-3.5355,9.8065e-15,3.5355,5,3.5355,4.4097e-14,-3.5355,-5,
-3.5355,-2.6945e-14,3.5355,5,3.5355,9.7941e-15,-3.5355,-5,-3.5355,7.3572e-15,3.5355,5,
3.5355,4.6546e-14,-3.5355,-5,-3.5355,-2.9395e-14,3.5355,5,3.5355,1.2243e-14,-3.5355,-5,
-3.5355,4.9079e-15,3.5355,5,3.5355,4.8995e-14,-3.5355,-5,-3.5355,-3.1844e-14,3.5355,5,
3.5355,1.4693e-14,-3.5355,-5,-3.5355,2.4586e-15,3.5355,5,3.5355,5.1444e-14,-3.5355,-5,
-3.5355,3.6761e-14,3.5355,5,3.5355,1.7142e-14,-3.5355,-5,-3.5355,-7.1045e-14,3.5355,5,
3.5355,-1.7161e-14,-3.5355,-5,-3.5355,-3.6742e-14,3.5355,5,3.5355,9.0646e-14,-3.5355,-5,
-3.5355,-2.44e-15,3.5355,5,3.5355,5.6343e-14,-3.5355,-5,-3.5355,3.1862e-14,3.5355,5,1,
0.70711,6.1232e-17,-0.70711,-1,-0.70711,-1.837e-16,0.70711,1,0.70711,3.0616e-16,-0.70711,
-1,-0.70711,-4.2863e-16,0.70711,1,5,3.5355,3.0616e-16,-3.5355,-5,-3.5355,-9.1849e-16,
3.5355,5,3.5355,1.5308e-15,-3.5355,-5,-3.5355,-2.1431e-15,3.5355,5,3.5355,2.7555e-15,
-3.5355,-5,-3.5355,-1.225e-14,3.5355,5,3.5355,-4.9017e-15,-3.5355,-5,-3.5355,-1.3474e-14,
3.5355,5,3.5355,-3.677e-15,-3.5355,-5,-3.5355,-1.4699e-14,3.5355,5,3.5355,-2.4524e-15,
-3.5355,-5,-3.5355,-1.5924e-14,3.5355,5,3.5355,-1.2277e-15,-3.5355,-5,-3.5355,-1.7148e-14,
3.5355,5,3.5355,-3.0949e-18,-3.5355,-5,-3.5355,-1.8373e-14,3.5355,5,3.5355,1.2216e-15,
-3.5355,-5,-3.5355,-1.9597e-14,3.5355,5,3.5355,2.4462e-15,-3.5355,-5,-3.5355,-2.0822e-14,
3.5355,5,3.5355,3.9198e-14,-3.5355,-5,-3.5355,-2.2047e-14,3.5355,5,3.5355,4.8955e-15,
-3.5355,-5,-3.5355,1.2256e-14,3.5355,5,3.5355,4.1647e-14,-3.5355,-5,-3.5355,-2.4496e-14,
3.5355,5,3.5355,7.3448e-15,-3.5355,-5,-3.5355,9.8065e-15,3.5355,5,3.5355,4.4097e-14,
-3.5355,-5,-3.5355,-2.6945e-14,3.5355,5,3.5355,9.7941e-15,-3.5355,-5,-3.5355,7.3572e-15,
3.5355,5,3.5355,4.6546e-14,-3.5355,-5,-3.5355,-2.9395e-14,3.5355,5,3.5355,1.2243e-14,
-3.5355,-5,-3.5355,4.9079e-15,3.5355,5,3.5355,4.8995e-14,-3.5355,-5,-3.5355,-3.1844e-14,
3.5355,5,3.5355,1.4693e-14,-3.5355,-5,-3.5355,2.4586e-15,3.5355,5,3.5355,5.1444e-14,
-3.5355,-5,-3.5355,3.6761e-14,3.5355,5,3.5355,1.7142e-14,-3.5355,-5,-3.5355,-7.1045e-14,
3.5355,5,3.5355,-1.7161e-14,-3.5355,-5,-3.5355,-3.6742e-14,3.5355,5,3.5355,9.0646e-14,
-3.5355,-5,-3.5355,-2.44e-15,3.5355,5,3.5355,5.6343e-14,-3.5355,-5,-3.5355,3.1862e-14,
3.5355,5,1,0.70711,6.1232e-17,-0.70711,-1,-0.70711,-1.837e-16,0.70711,1,0.70711,3.0616e-16,
-0.70711,-1,-0.70711,-4.2863e-16,0.70711,1,5,3.5355,3.0616e-16,-3.5355,-5,-3.5355,
-9.1849e-16,3.5355,5,3.5355,1.5308e-15,-3.5355,-5,-3.5355,-2.1431e-15,3.5355,5,3.5355,
2.7555e-15,-3.5355,-5,-3.5355,-1.225e-14,3.5355,5,3.5355,-4.9017e-15,-3.5355,-5,-3.5355,
-1.3474e-14,3.5355,5,3.5355,-3.677e-15,-3.5355,-5,-3.5355,-1.4699e-14,3.5355,5,3.5355,
-2.4524e-15,-3.5355,-5,-3.5355,-1.5924e-14,3.5355,5,3.5355,-1.2277e-15,-3.5355,-5,
-3.5355,-1.7148e-14,3.5355,5,3.5355,-3.0949e-18,-3.5355,-5,-3.5355,-1.8373e-14,3.5355,
5,3.5355,1.2216e-15,-3.5355,-5,-3.5355,-1.9597e-14,3.5355,5,3.5355,2.4462e-15,-3.5355,
-5,-3.5355,-2.0822e-14,3.5355,5,3.5355,3.9198e-14,-3.5355,-5,-3.5355,-2.2047e-14,3.5355,
5,3.5355,4.8955e-15,-3.5355,-5,-3.5355,1.2256e-14,3.5355,5,3.5355,4.1647e-14,-3.5355,
-5,-3.5355,-2.4496e-14,3.5355,5,3.5355,7.3448e-15,-3.5355,-5,-3.5355,9.8065e-15,3.5355,
5,3.5355,4.4097e-14,-3.5355,-5,-3.5355,-2.6945e-14,3.5355,5,3.5355,9.7941e-15,-3.5355,
-5,-3.5355,7.3572e-15,3.5355,5,3.5355,4.6546e-14,-3.5355,-5,-3.5355,-2.9395e-14,3.5355,
5,3.5355,1.2243e-14,-3.5355,-5,-3.5355,4.9079e-15,3.5355,5,3.5355,4.8995e-14,-3.5355,
-5,-3.5355,-3.1844e-14,3.5355,5,3.5355,1.4693e-14,-3.5355,-5,-3.5355,2.4586e-15,3.5355,
5,3.5355,5.1444e-14,-3.5355,-5,-3.5355,3.6761e-14,3.5355,5,3.5355,1.7142e-14,-3.5355,
-5,-3.5355,-7.1045e-14,3.5355,5,3.5355,-1.7161e-14,-3.5355,-5,-3.5355,-3.6742e-14,
3.5355,5,3.5355,9.0646e-14,-3.5355,-5,-3.5355,-2.44e-15,3.5355,5,3.5355,5.6343e-14,
-3.5355,-5,-3.5355,3.1862e-14,3.5355,5,9001};

*/

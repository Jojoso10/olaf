struct date{ int d, m, y; };
int M_size[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
date today;

bool is_leap(int n){
    if(n%4)return false;
    if(n%100)return true;
    if(n%400)return false;
    return true;
}

date next_day(date D){
    if(is_leap(D.y))M_size[1] = 29; else M_size[1] = 28;
    if(D.d < M_size[D.m-1]){D.d++; return D;} D.d = 1;
    if(D.m < 12){D.m++; return D;} D.m = 1;
    D.y++;
    return D;
}

// Este tramo te dice el signo zodiacal correspondiente una fecha
string Z_sign[12] = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"};
int Z_cota[12] = {21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};
string zodiac(date D){
    int it = D.m-1;
    if(D.d >= Z_cota[D.m-1])it = (it+1)%12;
    return Z_sign[it];
}


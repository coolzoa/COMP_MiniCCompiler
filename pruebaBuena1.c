int main ()
{
	int a,b,c,d ,s,r,p,q;
	b = 2; c = 1;
	a = b + c;


	if (a <= b && b <= c || a == b){
		
		if (a <= c){
			a = b;
		}else{
			c = b;
		}
	}


	switch(a)
	{
		case 0: s=1+4;
		
		case 1:
		{
			a=b;
			switch(b+2)
			{
				case 2: d=b+c;
				break;
				case 3: ;
				case 4: c=r;
				break;
			}
		} 
		case 2: s=2;
		break;
		case 3: s=3;
		break;
		case 4: s=7;
		case 5: s=9;
		break;
		default : p=q;
		break;
	}
	while(a+b*c)
	{
		if(a>b)
		{
			a=b;
		}
		else
		{
			c=d;
		}
		d=p*q+c*(a+b);
		q=r;
	}
}

%wave equation explicit
format bank
u=input('u=');
x_0=input('x_0=');x_n=input('x_n=');
t_0=input('t_0=');t_n=input('t_n=');
deltax=input('h=');r=input('r=');deltat=(sqrt(r).*deltax)./u;
x=[x_0:deltax:x_n];
border_1=input('Q(x=0)=');border_2=input('Q(x=x_n)=');
initial=input('Q(t=0)=');
m=((t_n-t_0)./deltat);n=((x_n-x_0)./deltax);
m=ceil(m)+1;n=ceil(n)+1;
Q=zeros(m,n);
Q(1:m,1)=border_1;Q(1:m,n)=border_2;
Q(1,1:n)=initial;
for j=2:n-1
    Q(2,j)=(1-r).*Q(1,j)+(r./2).*[Q(1,j+1)+Q(1,j-1)]
end
for i=2:m-1
    for j=2:n-1
        Q(i+1,j)=Q(i,j+1)+Q(i,j-1)-Q(i-1,j)
    end
end


#include "ft_printf.h"
#include "libft/libft.h"


int main(void)
{
	char *str  = "Hello World!";
	//unsigned int x = 4294967295;
	
	printf("\n\n");


	printf("\nUNPRINTABLE CHAR\n");
	printf("\nft_printf returns %d\n", ft_printf("\001\002\007\v\010\f\r\n"));
	printf("\nprintf returns %d\n", printf("\001\002\007\v\010\f\r\n"));


	printf("\nCHAR\n");
	printf("\nft_printf returns %d\n", ft_printf("test with char %c", 'c'));
	printf("\nprintf returns %d\n", printf("test with char %c", 'c'));


	printf("\nSTRING\n");
	printf("\nft_printf returns %d\n", ft_printf("test with string %s", str));
	printf("\nprintf returns %d\n", printf("test with string %s", str));

	printf("\nSTRING\n");
	printf("\nft_printf returns %d\n", ft_printf("test with string %s", (char *)NULL));
	printf("\nprintf returns %d\n", printf("test with string %s", (char *)NULL));


	printf("\nINT\n");
	printf("\nft_printf returns %d\n", ft_printf("test with int %d and %i and %d", 0, -2223, INT_MIN));
	printf("\nprintf returns %d\n", printf("test with int %d and %i and %d", 0, -2223, INT_MIN));

	printf("\nPOINTER\n");
	printf("\nft_printf returns %d\n", ft_printf("test with pointer %p", str));
	printf("\nprintf returns %d\n", printf("test with pointer %p", str));

	printf("\nPOINTER\n");
	printf("\nft_printf returns %d\n", ft_printf("test with pointer %p", NULL));
	printf("\nprintf returns %d\n", printf("test with pointer %p", NULL));

	printf("\nUNSIGNED INT\n");
	printf("\nft_printf returns %d\n", ft_printf("unsigned int is %u %u %u", 0, -11, UINT_MAX));
	printf("\nprintf returns %d\n", printf("unsigned int is %u %u %u", 0, -11, UINT_MAX));

	printf("\nHEXADESIMAL LOW\n");
	printf("\nft_printf returns %d\n", ft_printf("hexadecimal small is %x", 123456));
	printf("\nprintf returns %d\n", printf("hexadecimal small is %x", 123456));

	printf("\nHEXADESIMAL UP\n");
	printf("\nft_printf returns %d\n", ft_printf("hexadecimal up is %X", 0));
	printf("\nprintf returns %d\n", printf("hexadecimal up is %X", 0));

	printf("\nSEVERAL\n");
	printf("\nft_printf returns %d\n", ft_printf("%p, %c, %i, %x", NULL, 't', 23, 654));
	printf("\nprintf returns %d\n", printf("%p, %c, %i, %x", NULL, 't', 23, 654));
	

	return (0);
}



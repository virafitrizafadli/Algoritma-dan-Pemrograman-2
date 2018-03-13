#include <stdio.h>
#include <conio.h>
#include <string.h>

int main() {  
	typedef struct{
		char kode[5];
		int qty;
		int jumlah;
	} Rekaman;
	
	Rekaman rektran;

	FILE *filetransaksi;

	float rata2, rata2_2, sum_jumlah2,sum_qty2; 
	int sum_jumlah, sum_qty;
	char Current_Kategori[5];

	filetransaksi = fopen("File Transaksi.txt","r");
	fscanf (filetransaksi, "%s %d %d", &rektran.kode, &rektran.qty, &rektran.jumlah);

	if(feof(filetransaksi)) {  
		printf("file kosong");
	} else {
		sum_jumlah2 = 0;
		sum_qty2 = 0;
		while(!feof(filetransaksi)){
			sum_qty = 0;
			sum_jumlah = 0;
			strcpy(Current_Kategori, rektran.kode);
			while(!feof(filetransaksi) && strcmp(Current_Kategori, rektran.kode) == 0){
				sum_jumlah = sum_jumlah + rektran.jumlah;
				sum_qty = sum_qty + rektran.qty;	
				fscanf(filetransaksi, "%s %d %d", &rektran.kode, &rektran.qty, &rektran.jumlah);
			}
			rata2 = sum_jumlah / sum_qty;
			printf("rata-rata harga kendaraan %s per kendaraan= %f\n",Current_Kategori,rata2);
			
			sum_jumlah2 = sum_jumlah2 + sum_jumlah;
			sum_qty2 = sum_qty2 + sum_qty;
			rata2_2 = sum_jumlah2 / sum_qty2;
		}
		printf("\nrata-rata harga keseluruhan kendaraan= %f\n", rata2_2);
	}
	
	fclose(filetransaksi);
	getche();
	return 0;
}

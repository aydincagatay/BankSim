#include <stdio.h> //author Çaðatay AYDIN
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 600 // giselerin calisma suresi...istediginiz gibi oynama yapabilirsiniz...
#define boyut 100
struct node {
	int data;
	struct node *next;
};
typedef struct {
	int cnt;
	struct node *front;
	struct node *rear;
} queue;
void initialize(queue *q) {
	q->cnt = 0; //müþteri sayýsýný ölçen counter
	q->front = q->rear = NULL;
}
int isEmpty(queue *q) { //boþ mu kontrolü
	return (q->cnt == 0);
}
int isFull(queue *q) { //dolu mu kontrolü
	return (q->cnt == boyut);
}
int dequeue(queue *q) {
	int x;
	if (!isEmpty(q)) {
		struct node *temp = q->front;
		x = temp->data;
		q->front = temp->next;
		free(temp);
		q->cnt--;
	}
	return x;
}
void enqueue(queue *q, int a) {
	if (!isFull(q)) {
		struct node *temp = (struct node *) malloc(sizeof(struct node));
		temp->next = NULL;
		temp->data = a;
		if (isEmpty(q)) {
			q->front = temp;
			q->rear = temp;
		} else {
			q->rear->next = temp;
			q->rear = temp;
		}
		q->cnt++;
	}
}
int dondur(int a) {
	int rastgele;
	rastgele = rand() % (4 + 1 - 1) + 1; //1-4 arasýnda iþlem otomatik seçiliyor
	if (rastgele == 1) { //eft istiyordur 3-10dk
		a = rand() % (10 + 1 - 3) + 3;
		printf("\nEft islemi gerceklestirelecek islem suresi %d dakika\t\t", a);
	}
	if (rastgele == 2) { //para çekmek istiyordur 1-7dk
		a = rand() % (7 + 1 - 1) + 1;
		printf("\nPara cekme islemi gerceklestirelecek islem suresi %d dakika \t",a);
	}
	if (rastgele == 3) { //kredi istiyordur 10-20dk
		a = rand() % (20 + 1 - 10) + 10;
		printf("\nKredi basvuru islemi gerceklestirelecek islem suresi %d dakika \t",a);
	}
	if (rastgele == 4) { //fatura istiyordur 2-12dk
		a = rand() % (12 + 1 - 2) + 2;
		printf("\nFatura  islemi gerceklestirelecek islem suresi %d dakika \t",a);
	}
	return a;
}
int main() {
	printf("Calisanlar %d dakika boyunca calisacaktir...", N);
	int zaman = 0;
	struct node *head1 = (struct node*) malloc(sizeof(struct node));// ayriyetten dizi olusturmak istemedim cunku bagli liste yapisi yukarda tanimliydi...
	struct node *temp1 = head1;
	struct node *head2 = (struct node*) malloc(sizeof(struct node));
	struct node *temp2 = head2;
	struct node *head3 = (struct node*) malloc(sizeof(struct node));
	struct node *temp3 = head3;
	head1->next = NULL;
	head2->next = NULL;
	head3->next = NULL;
	srand(time(NULL)); //burada rand fonksiyonunun ayni degerler vermesini istemiyoruz...
	int a, d, o1, o2, o3, p;
	int i = 0, f = 0, g = 0, o = 0, c1 = 0, c2 = 0, c3 = 0, a1 = 0, a2 = 0, a3 = 0;
	queue *q = (queue*) malloc(sizeof(queue));
	initialize(q); //ilk degerlere null atama islemi
	queue *q1 = (queue*) malloc(sizeof(queue)); //ilk çalýþan
	initialize(q1); //ilk degerlere null atama islemi
	queue *q2 = (queue*) malloc(sizeof(queue)); //ikinci çalýþan
	initialize(q2); //ilk degerlere null atama islemi
	queue *q3 = (queue*) malloc(sizeof(queue)); //üçüncü çalýþan
	initialize(q3); //ilk degerlere null atama islemi
	while (zaman < N + 10) { //dongu en fazla N+10 defa donecek cogu zaman donguden erken ciktigi icin dinamik calisabiliyor.
		//N+10 olmasinin sebebi donguden erken cikmasini engellemek.
		d = rand() % (5 + 1 - 0) + 0;//musterinin gelmesi 0-5dk. . . ayný anda birden fazla musterinin gelmesi dahil degildir.
		printf("\n%d. Musteri bankaya %d. dakikada geldi", ++i, zaman);
		a = dondur(a);			//yapilacak olan islemin suresini olusturma
		enqueue(q, a);			//musteriyi genel kuyruga ekleme
		if (q1->cnt == 0) {
			enqueue(q1, a);
			a1+=a;// a1,a2,a3 hizmet surelerini hesaplamak icin...
			printf("\n->Bir musteri 1. gisede islemini hallediyor.");
			c1++;// c1,c2,c3 hizmet verilen musterileri saymak icin....
			temp1->data = dequeue(q) + zaman;
			o1 = temp1->data - zaman;//o1,o2,o3 en uzun bekleyen musteriyi bulmak icin...
			p += o1;
			if(temp1->data>N){ // belirlenen zaman sabiti N eger asilirsa Banka kapandi. Musteri daha sonra gelecek mesajini versin
				printf("Banka kapandi. Musteri daha sonra gelecek");		
			}
			else printf("\nMusterinin bankadan ayrilacagi sure : %d\n", temp1->data);
		} else if (q2->cnt == 0) {
			enqueue(q2, a);
			a2+=a;// a1,a2,a3 hizmet surelerini hesaplamak icin...
			printf("\n->Bir musteri 2. gisede islemini hallediyor.");
			c2++;// c1,c2,c3 hizmet verilen musterileri saymak icin....
			temp2->data = dequeue(q) + zaman;
			o2 = temp2->data - zaman;//o1,o2,o3 en uzun bekleyen musteriyi bulmak icin...
			p += o2;
			if(temp2->data>N){// belirlenen zaman sabiti N eger asilirsa Banka kapandi. Musteri daha sonra gelecek mesajini versin
				printf("Banka kapandi. Musteri daha sonra gelecek");		
			}
			else printf("\nMusterinin bankadan ayrilacagi sure : %d\n", temp2->data);
		} else if (q3->cnt == 0) {
			enqueue(q3, a);
			a3+=a;// a1,a2,a3 hizmet surelerini hesaplamak icin...
			printf("\n->Bir musteri 3. gisede islemini hallediyor.");
			c3++;// c1,c2,c3 hizmet verilen musterileri saymak icin....
			temp3->data = dequeue(q) + zaman;
			o3 = temp3->data - zaman;//o1,o2,o3 en uzun bekleyen musteriyi bulmak icin...
			p += o3;
			if(temp3->data>N){// belirlenen zaman sabiti N eger asilirsa Banka kapandi. Musteri daha sonra gelecek mesajini versin
				printf("Banka kapandi. Musteri daha sonra gelecek");		
			}
			else printf("\nMusterinin bankadan ayrilacagi sure : %d\n", temp3->data);
		} else {
			f++;			//kuyrukta olusan en fazla sirayi hesaplamak icin...
			if (f > g) {
				g = f;
			}
		}
		if (o1 < o) {//eger daha buyuk o degiskeni gelirse atama yapilsin; en fazla bekleyen musterinin bekleme suresini hesaplamak icin...
			o =+ o1;
		}
		if (o2 > o) {
			o =+ o2;
		}
		if (o3 > o) {
			o =+ o3;
		}
		if (temp1->data < zaman) {
			printf("\n1. gise bos durumda", dequeue(q1)); //calisanlarin musteriyle isi bitti mi kontrolu
		}
		if (temp2->data < zaman) {
			printf("\n2. gise bos durumda", dequeue(q2));
		}
		if (temp3->data < zaman) {
			printf("\n3. gise bos durumda", dequeue(q3));
		}
		zaman += d;//musterinin gelme suresini zamana ekleme
		printf("\nDakika=%d", zaman);
		if (zaman > N - 1) {//zaman doldu mu kontrolu...prensip meselesi son dakika gelen musteriyi kabul etmiyoruz
							//hatta islemi suren musteri varsa onu da evine yolluyoruz
							//cunku calisanlarimiz N dakika sonunda evlerine gidecekler
			printf("\nBanka kapaniyor\nSon musterilerin islemleri hallediliyor...");
			printf("\n-----Istatistikler-----");
			printf("\nHerhangi bir zamanda kuyrukta olusan en fazla sira = %d kisi",f);
			printf("\nKuyrukta en uzun bekleyen musterinin bekleme suresi = %d dakika",o);
			printf("\nKuyrukta bekleyen bir musterinin bekleyecegi ortalama sure = %d dakika",p / i);
			printf("\n1. gisenin hizmet verdigi musteri sayisi=%d \n2. gisenin hizmet verdigi musteri sayisi=%d\n3. gisenin hizmet verdigi musteri sayisi=%d",c1,c2,c3);
			printf("\n---Giselerin, musterilere ortalama verdigi hizmet sureleri---");
			printf("\n1. gise = %d dakika, 2. gise = %d dakika, 3. gise = %d dakika",a1/c1,a2/c2,a3/c3);
			getch();
			exit(1);
		}
	}
}


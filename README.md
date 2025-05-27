Objaśnienia: 

Ekran wymaga aktualizacji buforu i dla koloru czarnego i dla koloru czerwonego - jak tylko dla jednego zaktualizujesz to bufor drugiego zapełni się syfilisem i taki też efekt będzie na ekranie - to co chcesz wyświetlić upaćkane od losowego syfilisu.

W mainie zakomentowana jest funkcja rozpoczynająca się od EPD_Init() - (inicjalizacji ekranu) 
Funkcja działa i poprawnie wyświetla 3 prostokąty na ekranie - biały, czerwony i czarny (może być w innej kolejności)

Aktualnie rozwijana funkcja to demo dla naszego ekranu 2.9"
znajduje się ona w pliku demo_2_9ich.c

Funkcja zawiera wszystkie potrzebne komendy do wywołania ekranu po resecie płytki
Kierujcie się komentarzami zamieszczonymi w pliku - większosć to będą moje 

TODO:

 - trzeba ogarnąć plik z fontem w danym rozmiarze, dla polskich znaków. Aktualnie wykorzystywany jest plik bez znaków polskich
 - Fajnie by ogarnąć funkcję ustawiającą rotację ekranu dla aktualnych funkcji print np.:
void Paint_NewImage(uint8_t *image, uint16_t Width, uint16_t Height, uint16_t Rotate, uint16_t Color) {
	Paint.Image = NULL;                                                       /|\
	Paint.Image = image;                                                       |
                                                                                   |
                                                         Żeby od razu był ustalony rotate i się nam nie jebało

                                            

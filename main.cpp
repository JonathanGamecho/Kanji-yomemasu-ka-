/*
Kanji, yomemasu ka? v1.2.1

Funcionamiento:

lista de palabras kanji separadas por espacios ('+' en kanjis por problemas tecnicos)

numero de palabras = numero de espacios 

seleccionar palabra(){

	numero aleatorio entre 1 y (numero de palabras)
	ese numero es el fin palabra
	se guarda la posicion [] de fin palabra en posterior
	el [] fin palabra anterior se guarda en anterior

	kanji seleccionado entre espacio anterior y espacio posterior
	lo mismo para romaji
}

ESQUEMA DEL JUEGO

Dos modalidades, clαsico e infinito

(Clαsico)
Cinco palabras, cinco intentos por palabra

(Infinito)
Palabras infinitas, un punto por palabra, cada palabra errσnea quita 3 puntos
Empiezas con 9 puntos
0 puntos = Game Over


VERSIONES

(nota: agpal significa agrega palabras)

v0.1 configura selecpalabra, pregunta una sola palabra
v1.0 crea el juego, con 2 modalidades (clasico e infinito)
v1.1 agrega la modalidad 69 (ver la lista de palabras)
	 y agrega color al responder bien o mal
v1.2 al finalizar vuelves a la pantalla de inicio
	 y agrega cerrar programa (modalidad 9)
	v1.2.1  agpal todos los n5 desconocidos
v1.3 palabra "finalizar" para, finalizar
	 y agpal 100 primeros n4 sustantivos desc.
	v1.3.1  agpal todos los n4 sustantivos desc.
	v1.3.2  agpal todos los n4 verbos desc.
	v1.3.3  agpal canciones up to mahiru no tsuki akari (»κΝ¬³ΘυΜζ€ΘAΗ€Ή³­ΘιΎ―ACΝΖίsΧA½Κ³tA^ΜΎ©θj 
v1.4 nos pasamos al proyecto! y agrega sonido fallo, acierto y felicitaciones
v1.5 agrega modalidad 3 y 4, zonas en clasico e infinito
v1.6 agrega musica de fondo
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <graphics.h>

using namespace std;

char version[]="1.6";


//lista de palabras en kanji
//			 "ΓΕ+ήϋ+ή+Τ+j+·Τ+sή+Ει+χ©+P«+±­+β΅’+ΰκι+svc+΅+Yή+w€+«i+li+F+―ή+§κ+πκι+§€+©κι+Ίΰ+ζΚ+Μ’+sυ+kι+³X+Sι+φκι+½+«+¦έ+πs+ Ψθ+ΐ€+fG+y+~£ι+M+Ώl+C+Ωπ++MΤ+γβΗ+O+Ό[+[+ΰΚ+z+O«+Ήi+Χ+ει+ψ«·¦ι+XΆ+?+{θ+ϋάι+lι+sεκι+Κ+·+Ο¦ι+T?+H©+Z―ι++Uι+ͺή+Μ·+n―ι+ψή+rΨκι+?+uΤ+χ’+Ώι+―ι+ΤΆι+Ψ§+όH+€+Ι+€+ϊ?+~θGΒ+Ήι+κι+ρι+hκι+Σι+¦ι+₯ή+Ύι+²ΙΘι+^Τ+₯€+β¦ι+υι+ψΑz·+E€+Jίι+Fι+}?+Έ­+v·+ή+Πt―ι+Β+ικι+Qι+ρι+’΅γͺι+ίι+}¦ι+ό©€+°ι+Όι+‘ι+΅κι+Βι+¦°ι+ι+cι+ζθ·¦ι+Gκι+hι+ή+Α­+N±·+xκι+ι+άκι+άι+Βι+T·+·΅γ°ι+?+Gι+Άι+²Χι+ΆΆι+ι+Οή+iή+ΜΔι+«θι+«·+Δι+qΛι+θ`€+Ν―ι+ζθΦ¦ι+±­+±―ι+ίά¦ι+Π―ι+Aκι+ήι+`¦ι+A¦ι+f€+ΕΒ+Ϊι+Κ·+Κκι+¦©·+¦­+κι+Δ―ι+Δ­+c+²Ζ+k+Ή+j+χ+»+ή@+I+aΆ+τ+θά+J+K+Wο++r+Α}+°?+s+r+σt+^]θ+ ++\K+\θ+p+pΣ+p+\ρ++wΦ+cO+`+‘X+s+Ξ+ΨΘ++Ά+ρKΔ+l`+υ’+A+¨μ³ρ+?γ+¨Υθ+¨©’+¨yY+΅όκ+¨ξ+e+β[+πj+p+―η+·Ω+β+YΖ+­‘+Ά½+ΆY+Όm+ό+w+ν+Π·+Πο+s++dϋ+±++s―+i¨+V·Π+eΨ+Έs+Ί+HΏi+Πξ+«+ο‘+K΅+cκ+κΆ½+++Μ+_Π+lϋ+«T+\ͺ+_Ή+Ϋ·+Θw+Ύ+οc+οcΊ+οκ+οb+Ξ+iD+―+Ζΰ+Εμw+ΦW+Ρ+φδ+vζ+o±+x@+oΟ+©¨+€+€Ί+iF+@ο+ί+¦+Gί+DΤ+K₯+Z·+u°+xO+u`+HΖ+Hκ+φ±υ+wZ+πΚ+³η+³ο+»‘+£+}s+ζ+^ρ+όθ+₯A+‘+ΤρV+Δΰ+{+Τg+κ+όpΩ+fΥ+·+Άw+Ά»+Ά@+n+Σ+Λ+Τκ+εΜ+g[+j«+dρ+d+D_+?¨+Ήο+}+Ά+sΦ+D+M+zc+Κ+΄φ+Ίh+Zp+ο+q©+γ?+Τ©+½Ξ+­Ή+Ρ+E+ςsκ+Τ+xέ+v΅Τθ+|σ+―+@₯+ϊ+ΘO+γw+Θγ+ΘΊ+Θΰ+cΙ+έ·+Θͺι+­+ΐΧι+x+§h+Χ’+y’+·’+Ο’+c+{χ+κϊ+γ+ͺS?+m+[ϋ+[Ρ+¨ +κπN+LΊ+μΆ+wL+|+ςR+g+π·_+C+NM+ε+Zϊ+¨θ³ρ+20Ξ+20ϊ+Ι+r+ψ+«+Ψ+iX+k+M++ϋ+t+DM+@+εgΩ+Μα+Κι+li+Όϋ+ό@+LΌ+μΤ+―w+μΨ+ΑΚ+ϋό+¬κι+τσ+£­+βίι+Φ¦ι+Ξ²+μ+H+©H+°ι+Ό++μ+[H+γά·+ά+Eκ++·+όw+Λ+Κθ+vw+«+M+xι+ϊ³+ι§+Κ€+Ώ+Χ©’+N+¬Ρ+³Θ+³Ί+³t+i+Η+ηΔι+|κι+όι+Ί°ι+‘ι+KΛι+ΊΦ+·j+Κu++Cέ+G+¬ΰ+I++ΉH+lΒp+Θͺθp+x@+Ζλ+ϊΤ+o±+nk+θp+Ξ+Ϋ+ρΔ+±+³φ+Ε’+όDϋ++¨ήθ+Ό+Τ+‘G+­+Σ©+’+»+XΦΗ+Z+Α΅’+Ό+αΎ++΅΅’+Ξίι+φβ©+Ι’+r+έϋ+q+K+ϋ+Χς+πι+¬sι+Ό+ά+Iθ+A+υ+ΑΙ+¨j’+G+Σθ+Ύγϊ+N+ΪΉι++άι+­+ρ"
char kanji[]="ΓΕ+ήϋ+ή+Τ+j+·Τ+sή+Ει+χ©+P«+±­+β΅’+ΰκι+svc+΅+Yή+w€+«i+li+F+―ή+§κ+πκι+§€+©κι+Ίΰ+ζΚ+Μ’+sυ+kι+³X+Sι+φκι+½+«+¦έ+πs+ Ψθ+ΐ€+fG+y+~£ι+M+Ώl+C+Ωπ++MΤ+γβΗ+O+Ό[+[+ΰΚ+z+O«+Ήi+Χ+ει+ψ«·¦ι+XΆ+?+{θ+ϋάι+lι+sεκι+Κ+·+Ο¦ι+T?+H©+Z―ι++Uι+ͺή+Μ·+n―ι+ψή+rΨκι+?+uΤ+χ’+Ώι+―ι+ΤΆι+Ψ§+όH+€+Ι+€+ϊ?+~θGΒ+Ήι+κι+ρι+hκι+Σι+¦ι+₯ή+Ύι+²ΙΘι+^Τ+₯€+β¦ι+υι+ψΑz·+E€+Jίι+Fι+}?+Έ­+v·+ή+Πt―ι+Β+ικι+Qι+ρι+’΅γͺι+ίι+}¦ι+ό©€+°ι+Όι+‘ι+΅κι+Βι+¦°ι+ι+cι+ζθ·¦ι+Gκι+hι+ή+Α­+N±·+xκι+ι+άκι+άι+Βι+T·+·΅γ°ι+?+Gι+Άι+²Χι+ΆΆι+ι+Οή+iή+ΜΔι+«θι+«·+Δι+qΛι+θ`€+Ν―ι+ζθΦ¦ι+±­+±―ι+ίά¦ι+Π―ι+Aκι+ήι+`¦ι+A¦ι+f€+ΕΒ+Ϊι+Κ·+Κκι+¦©·+¦­+κι+Δ―ι+Δ­+c+²Ζ+k+Ή+j+χ+»+ή@+I+aΆ+τ+θά+J+K+Wο++r+Α}+°?+s+r+σt+^]θ+ ++p+pΣ+p++wΦ+cO+`+‘X+s+Ξ+ΨΘ++Ά+ρKΔ+l`+υ’+A+¨μ³ρ+?γ+¨Υθ+¨©’+¨yY+΅όκ+¨ξ+e+β[+πj+p+―η+·Ω+β+YΖ+­‘+Ά½+ΆY+Όm+ό+w+ν+Π·+Πο+s++dϋ+±++s―+i¨+V·Π+eΨ+Έs+Ί+HΏi+Πξ+«+ο‘+K΅+cκ+κΆ½+++Μ+_Π+lϋ+«T+\ͺ+_Ή+Ϋ·+Θw+Ύ+οc+οcΊ+οκ+οb+Ξ+iD+―+Ζΰ+Εμw+ΦW+Ρ+φδ+vζ+o±+x@+oΟ+©¨+€+€Ί+iF+@ο+ί+¦+Gί+DΤ+K₯+Z·+u°+xO+u`+HΖ+Hκ+φ±υ+wZ+πΚ+³η+³ο+»‘+£+}s+ζ+^ρ+όθ+₯A+‘+ΤρV+Δΰ+{+Τg+κ+όpΩ+fΥ+·+Άw+Ά»+Ά@+n+Σ+Λ+Τκ+εΜ+g[+j«+dρ+d+D_+?¨+Ήο+}+Ά+sΦ+D+M+zc+Κ+΄φ+Ίh+Zp+ο+q©+γ?+Τ©+½Ξ+­Ή+Ρ+E+ςsκ+Τ+xέ+v΅Τθ+|σ+―+@₯+ϊ+ΘO+γw+Θγ+ΘΊ+Θΰ+cΙ+έ·+Θͺι+­+ΐΧι+x+§h+Χ’+y’+·’+Ο’+c+{χ+κϊ+γ+ͺS?+m+[ϋ+[Ρ+¨ +κπN+LΊ+μΆ+wL+|+ςR+g+π·_+C+NM+ε+Zϊ+¨θ³ρ+20Ξ+20ϊ+Ι+r+ψ+«+Ψ+iX+k+M++ϋ+t+DM+@+εgΩ+Μα+Κι+li+Όϋ+ό@+LΌ+μΤ+―w+μΨ+ΑΚ+ϋό+¬κι+τσ+£­+βίι+Φ¦ι+Ξ²+μ+H+©H+°ι+Ό++μ+[H+γά·+ά+Eκ++·+όw+Λ+Κθ+vw+«+M+xι+ϊ³+ι§+Κ€+Ώ+Χ©’+N+¬Ρ+³Θ+³Ί+³t+i+Η+ηΔι+|κι+όι+Ί°ι+‘ι+KΛι+ΊΦ+·j+Κu++Cέ+G+¬ΰ+I++ΉH+lΒp+Θͺθp+x@+Ζλ+ϊΤ+o±+nk+θp+Ξ+Ϋ+ρΔ+±+³φ+Ε’+όDϋ++¨ήθ+Ό+Τ+‘G+­+Σ©+’+»+XΦΗ+Z+Α΅’+Ό+αΎ++΅΅’+Ξίι+φβ©+Ι’+r+έϋ+q+K+ϋ+Χς+πι+¬sι+Ό+ά+Iθ+A+υ+ΑΙ+¨j’+G+Σθ+Ύγϊ+N+ΪΉι++άι+­+ρ";
char seleckanji[100];//palabra seleccionada
char seleckanjianterior[100];
//lista de palabras en romaji 
char romaji[]="kurayami kanata kizamu haguruma hoho hazama haramu naderu kasuka kagayaki michibiku sabishii umoreru fushigi mujun nayamu seou seikaku jinkaku shosen dourui tachiba akireru au mitoreru heitai gamen erai fukai sakanoboru motomoto tsumeru kuzureru byoudou keno urami guchi uragiri mayou suteki rakushou yokubaru shingou kachi uwaki benkai suukagetsu moteasobu kouishou jizen hanpa hashi naimen risou aki shitto shoi satoru hikikaeru kousei hagu ikari osamaru nonoshiru futekusareru kekka masu taeru uppun kasuka tokeru ai furu kajikamu taion tokeru nijimu togireru kagi shunkan kui michiru kakeru tojiru kodachi senro sou hekiraku kanau kitai furisobotsu yaseru yogoreru yoru yureru ayamaru fueru fumu futoru goranninaru hakobu harau hieru hikaru hikkosu hirou homeru inoru isogu itadaku itasu kamu katadzukeru katsu kureru mairu mawaru meshiagaru modoru mukaeru mukau nageru naoru naoru nareru naru nigeru niru nokoru norikaeru nureru nuru nusumu odoroku okosu okureru okuru oreru oru ossharu sagasu sashiageru sawagu sawaru shikaru shiraberu shoujiru suberu sumu susumu suteru tariru tasu tateru tazuneru tetsudau todokeru torikaeru tsudzuku tsudzukeru tsukamaeru tsukeru tsureru tsuru tsutaeru ueru ukagau utsu utsuru utsusu wakareru wakasu waku wareru yakeru yaku sofu sotsugyou soudan suidou suiei sumi suna taiin tana tanjou tatami tebukuro teinei tekitou tenrankai tera tochuu tokkyuu tokoya tsugou ude uketsuke untenshu ura wariai you youi youji yu yubiwa zannen minato miso miyako mizuumi momen mushi nama nikaidate ningyou nioi nodo ojousan okujou omatsuri omimai omiyage oshiire otaku oya reibou rekishi riyou rusu ryokan saka sangyou seiji seimei seisan seiyou sen senaka sensou shachou shakai shi shiai shikata shiken shima shimin shinamono shinbunsha shinsetsu shippai shitagi shokuryouhin shoukai shourai shumi shuukan sobo isshoukenmei ito ji jiko jinja jinkou jiten juubun juudou kachou kagaku kagami kaigi kaigishitsu kaijou kaiwa kaji kakkou kami kanai kangofu kankei ke kega keikaku keiken keisatsu keizai kenbutsu kenkyuu kenkyuushitsu keshigi kikai kinjo kinu kisetsu kisha kisoku kouchou koudou kougai kougi kougyou koujou koumuin koutougakkou koutsuu kyouiku kyoukai kyoumi kyousou kyuukou manga mannaka mawari aisatsu aji akanbou annai bai bangumi basho bijutsukan boueki buchou bungaku bunka bunpou chiri chuui chuusha chuushajou daitai danbou dansei denpou dentou dorobou doubutsuen dougu eda enryo fuben fune fune futon futsuu genin geshuku gijutsu guai haiken haisha hanami hantai hatsuon hayashi hige hikoujou hiruma hiruyasumi hisashiburi honyaku hoshi houritsu housou igai igaku ijou ika inai inaka kasu magaru migaku naraberu choudo rippa hosoi karui nurui urusai tate toriniku tsuitachi uwagi yaoya youfuku yuugata yuuhan onaka ototoshi rouka sakubun sebiro souji takusan koucha kousaten kutsu mannenhitsu mon muika omawarisan hatachi hatsuka hima ike jibiki jisho kippu kissaten kita enpitsu fuutou gyuunyuu hagaki haizara hana taishikan koshou tooru nedan ryouhou nyuuin yuumei yorokobu ryuugaku yasai tokubetsu houkou nagareru sentaku kawaku sameru kigaeru sekken yakyuu chuushoku choushoku nemuru nishi higashi minami yuushoku hagemasu namida shokuba mado osu nyuugaku to toori fuufu josei netsu odoru atsusa himitsu kayou kyuuryou komakai kenkou seiseki kyoukasho kyoushitsu kyoushi goukaku kabe sodateru taoreru kazaru sageru okuru tazuneru genkan chounan ichi ana kaigan zasshi shousetsu hiji makura douro yotsukado magarikado keisatsu katei kikan keiken jishin shujutsu yakedo kokusai teian jimusho kyouju katai kaisatsuguchi shio otsuri myouji henji fukuzatsu kawaku iken usui satou yuubinkyoku juusho suzushii shimei megane kaban kibishii tsutomeru nigiyaka yurui bin shouyu chawan fukushuu mayu kazegusuri sakuya hayaru hantsuki kenka senshu kikoku junbi tokuni oiwai hiza atari myougonichi kyonen noseru koshi tomaru kawaku ρ";
char selecromaji[100];//romaji seleccionado
char selecromajianterior[100];
int longitud_kanji,longitud_romaji;//longitud de la lista (caracteres)

int npalabras=0,nroma=0,aleatorio;//numero de palabras,espacio aleatorio,
int anteriork, posteriork,anteriorr, posteriorr;// posiciσn anterior, posiciσn posterior para kanji k y romaji r
int antkanterior=0, postkanterior=0, antranterior, postranterior;
int modalidad;
int longanteriork,longactualk,longanteriorr,longactualr;
bool verlista=false,cerrar=false,fin=false,zonas;
int superior,inferior,nzonas,seleczona,zonaset;
//										garbage value for set
int intento[100];
//seleccionar palabra y guardarla en seleckanji y selecromaji
void selecpalabra();
void juego();
void separar();
void intermitente(char frase[]);
void intermitentewon(char frase[]);
void definsup();
bool comprobarrepetidos(int partida),primero;


int main(){
	srand(time(NULL));
	sf::Music music;
	if (!music.openFromFile("fondo.ogg")){
    	cout<<"Error en musica de fondo";
	}
	music.play();


	primero=true;
	longitud_kanji=strlen(kanji);//conociendo el numero de caracteres totales
	longitud_romaji=strlen(romaji);//conociendo el numero de caracteres totales
	//conociendo el numero de palabras
	for(int i=0;i<longitud_kanji;i++){
		if(kanji[i]=='+'){
			npalabras++;
		}
	}
	for(int i=0;i<longitud_romaji;i++){
		if(romaji[i]==' '){
			nroma++;
		}
	}
	
	cout<<"numero de palabras: "<<npalabras<<endl;
	cout<<"numero de romajis: "<<nroma<<endl;
	separar();
	cout<<"Ajuste la pantalla\nSe recomienda encarecidamente leer las instrucciones\n(README)\n";system("PAUSE");
	juego();
	Sleep(700);
	separar();
	intermitentewon("Gracias por jugar!\nΏAΗίά·©B (Kanji, yomemasu ka?) v");intermitente(version);

	Sleep(1500);
	return 0;
}
void selecpalabra(){
	if(verlista==false){
		//establecemos palabra (espacio) random
		if(zonas==false){
			aleatorio=1+rand()%(npalabras);
		}
		if(zonas==true){
			definsup();
			aleatorio=inferior+rand()%(superior+1-inferior);
		}
	}
	//(kanji) guarda la posicion del espacio en posterior y en anterior
	bool encontrado=false;int j=0,contador=0;
	while(encontrado==false){
		if(kanji[j]=='+'){//busca los espacios
			contador++;
		}
		if(contador==aleatorio-1){
			if(kanji[j]=='+'){//espacio anterior
			anteriork=j;//guarda posicion
			}
			if(aleatorio==1){//si espacio anterior no existe
				anteriork=-1;
			}
		}
		if(contador==aleatorio){//llego al espacio posterior
			posteriork=j;//guarda posicion
			encontrado=true;
		}
		j++;//siguiente posicion
	}
	
	//guardar la palabra en seleckanji
	for(int j=anteriork+1;j<posteriork;j++){
		seleckanji[j-anteriork-1]=kanji[j];
	}
	if(posteriork-(anteriork+1)<postkanterior-(antkanterior+1)&&primero==false){
		for(int m=posteriork-anteriork-1; m<postkanterior-antkanterior+1; m++){
			seleckanji[m]=' ';
		}
	}
	
	//lo mismo para romaji (espacios normales)
	
	//(romaji) guarda la posicion del espacio en anterior y posterior
	encontrado=false;j=0,contador=0;
	while(encontrado==false){
		if(romaji[j]==' '){//busca los espacios
			contador++;
		}
		if(contador==aleatorio-1){
			if(romaji[j]==' '){//espacio anterior
			anteriorr=j;//guarda posicion
			}
			if(aleatorio==1){//si espacio anterior no existe
				anteriorr=-1;
			}
		}
		if(contador==aleatorio){//llego al espacio posterior
			posteriorr=j;//guarda posicion
			encontrado=true;
		}
		j++;//siguiente posicion
	}
	//guardar la palabra en selecromaji
	for(int j=anteriorr+1;j<posteriorr;j++){
		selecromaji[j-anteriorr-1]=romaji[j];
	}
	if(posteriorr-(anteriorr+1)<postranterior-(antranterior+1)&&primero==false){
		for(int m=posteriorr-anteriorr-1; m<postranterior-antranterior+1; m++){
			selecromaji[m]=' ';
		}
	}
	primero=false;
	antkanterior=anteriork;
	postkanterior=posteriork;
	antranterior=anteriorr;
	postranterior=posteriorr;
}
void juego(){
while(cerrar==false){
	char finalizar[]="finalizar";
	verlista=false;
	int puntos=0,puntosanteriores=0,fallos=0;
	separar();
	intermitentewon("ΏAΗίά·©B (Kanji, yomemasu ka?) v");intermitente(version);
	intermitente("Seleccione una modalidad de juego:\n1.Clasico\n2.Infinito\n3.Clasico (por zonas)\n4.Infinito (por zonas)\n9.Cerrar Programa\nSeleccion: ");
	//1.Clasico\n2.Infinito\n3.Clasico ()por zonas)\n9.Cerrar programa\nSeleccion: ");
	cin>>modalidad;Sleep(1000);
	if(modalidad==1){//modalidad clasica (cinco palabras, cinco intentos por palabra)
		zonas=false;
		for(int npartida=0;npartida<5;npartida++){//cinco palabras)
			selecpalabra(); //seleccionar palabra y guardarla en seleckanji y selecromaji
			char respuesta[]="Garbage";
			bool fallo=true;int iterador=0;
			while(fallo==true){
				Sleep(500);
				separar();
				intermitentewon("Puntos: ");cout<<puntos<<endl;
				intermitentewon("Fallos: ");cout<<fallos<<endl;
				//pide respuesta y la guarda
				intermitente("\nEscriba la lectura de esta palabra en romaji:");
				intermitente(seleckanji);
				intermitente("\nRespuesta: ");scanf("%s",respuesta);
				//comprueba si respuesta es correcta
				bool iguales=true;
				for(int i=0;i<strlen(respuesta);i++){
					if(respuesta[i]!=selecromaji[i]){
						iguales=false;
					}
				}
				int mal=0;
				for(int i=0;i<strlen(respuesta);i++){
					if(respuesta[i]==finalizar[i]){
						mal++;
					}
					if(mal==9){
						fin=true;
					}
					else{
						fin=false;
					}
				}
				if(fin==true){fallo=false;npartida=5;cerrar=true;}
				if(iguales==true&&strlen(respuesta)==posteriorr-anteriorr-1){
					system("color 0a");
					//sonido
					sf::SoundBuffer buffer;
					if (!buffer.loadFromFile("Acierto.wav")){
						intermitente("\nError de audio");
					}
					sf::Sound sound;
					sound.setBuffer(buffer);
					sound.play();
					
					fallo=false;intermitente("\nCorrecto!\n");puntos++;Sleep(750);
					system("color 07");
				}else{
					if(iterador!=4){
						system("color 0c");
						//sonido
						sf::SoundBuffer buffer;
						if (!buffer.loadFromFile("Fallo.wav")){
							intermitente("\nError de audio");
						}
						sf::Sound sound;
						sound.setBuffer(buffer);
						sound.play();
					
						intermitente("Incorrecto, intentelo de nuevo\n");iterador++;fallos++;Sleep(2500);
						system("color 07");
					}
					else{
						system("color 0c");
						//sonido
						sf::SoundBuffer buffer;
						if (!buffer.loadFromFile("Fallo.wav")){
							intermitente("\nError de audio");
						}
						sf::Sound sound;
						sound.setBuffer(buffer);
						sound.play();
					
						intermitentewon("Incorrecto, la respuesta correcta era: ");intermitente(selecromaji);fallos++;iterador++;fallo=false;Sleep(1000);
						system("color 07");
						}	
				}
			}intermitente("Continuemos...");
			//reinicia el estado de seleckanji,  selecromaji y respuesta
			for(int gn=0;gn<strlen(seleckanji); gn++){
				seleckanji[gn]=' ';
			}
			for(int gn=0;gn<strlen(selecromaji); gn++){
				selecromaji[gn]=' ';
			}
			for(int gn=0;gn<strlen(respuesta); gn++){
				respuesta[gn]=' ';
			}
		}
		Sleep(500);
		separar();
		intermitentewon("\nPuntos finales: ");cout<<puntos<<endl;
		intermitentewon("\nFallos totales: ");cout<<fallos<<endl;
		if(fallos>14){
			system("color 0c");
			intermitente("Recomendamos estudiar estas palabras, ya que tiene mas de 15 fallos.");
			system("color 07");
		}
		if(fallos==0){
			//sonido
			sf::SoundBuffer buffer;
			if (!buffer.loadFromFile("Felicitaciones.wav")){
				intermitente("\nError de audio");
			}
			sf::Sound sound;
			sound.setBuffer(buffer);
			sound.play();
			intermitente("\nIncreible, sin fallos!");
		}
		if(fin==false){
		system("PAUSE");
		}
	}
	if(modalidad==2){//modalidad infinita (mientras tengas puntos)
		zonas=false;
		puntos=9;
		while(puntos>0){//mientras tengas puntos
			Sleep(500);
			separar();
			selecpalabra(); //seleccionar palabra y guardarla en seleckanji y selecromaji
			char respuesta[]="Garbage";
			intermitentewon("Puntos: ");cout<<puntos<<endl;
			intermitente("Escriba la lectura de esta palabra en romaji:");
			intermitente(seleckanji);
			intermitente("\nRespuesta: ");scanf("%s",respuesta);
			//comprueba si respuesta es correcta
			bool iguales=true;
			for(int i=0;i<strlen(respuesta);i++){
				if(respuesta[i]!=selecromaji[i]){
					iguales=false;
				}
			}
			int mal=0;
			for(int i=0;i<strlen(respuesta);i++){
				if(respuesta[i]==finalizar[i]){
					mal++;
				}
				if(mal==9){
					fin=true;
				}
				else{
					fin=false;
				}
			}
			if(fin==true){puntos=0;cerrar=true;}
			if(iguales==true&&strlen(respuesta)==posteriorr-anteriorr-1){
				system("color 0a");
				//sonido
				sf::SoundBuffer buffer;
				if (!buffer.loadFromFile("Acierto.wav")){
					intermitente("\nError de audio");
				}
				sf::Sound sound;
				sound.setBuffer(buffer);
				sound.play();
					
				intermitente("\nCorrecto!\n");puntos++;
				system("color 07");
			}else{
				
				system("color 0c");
				//sonido
				sf::SoundBuffer buffer;
				if (!buffer.loadFromFile("Fallo.wav")){
					intermitente("\nError de audio");
				}
				sf::Sound sound;
				sound.setBuffer(buffer);
				sound.play();
					
				intermitentewon("Incorrecto, la respuesta correcta era: ");
				intermitente(selecromaji);
				system("color 07");
				if(fin==false){
				system("PAUSE");
				}
				puntos=puntos-3;
			}
			if(puntos%10==0&&puntos!=10){
				if(puntosanteriores!=puntos&&puntos>puntosanteriores){
					separar();
					//sonido
					sf::SoundBuffer buffer;
					if (!buffer.loadFromFile("Felicitaciones.wav")){
						intermitente("\nError de audio");
					}
					sf::Sound sound;
					sound.setBuffer(buffer);
					sound.play();
					
					intermitente("Increible! Mira cuantos puntos tienes!");
				}
				puntosanteriores=puntos;
			}
			//reinicia el estado de seleckanji,  selecromaji y respuesta
			for(int gn=0;gn<strlen(seleckanji); gn++){
				seleckanji[gn]=' ';
			}
			for(int gn=0;gn<strlen(selecromaji); gn++){
				selecromaji[gn]=' ';
			}
			for(int gn=0;gn<strlen(respuesta); gn++){
				respuesta[gn]=' ';
			}
		}
		separar();
		intermitente("Lamentablemente, se ha quedado sin puntos (Game Over)");
	}
	if(modalidad==69){//ver lista de palabras
		zonas=false;
		separar();
		if(npalabras==nroma){
			verlista=true;
			for(int k=1;k<npalabras+1;k++){
				aleatorio=npalabras+1-k;
				selecpalabra();
				cout<<"\nPalabra nro: "<<k<<endl;
				cout<<seleckanji<<endl<<selecromaji<<endl<<endl;
				
				//reinicia el estado de seleckanji y selecromaji
				for(int gn=0;gn<strlen(seleckanji); gn++){
					seleckanji[gn]=' ';
				}
				for(int gn=0;gn<strlen(selecromaji); gn++){
					selecromaji[gn]=' ';
				}
			}
			system("PAUSE");
		}else{
			cout<<"Error: el numero de palabras no coincide."<<endl;
			cout<<"Numero de kanjis: "<<npalabras<<endl<<"Numero de romajis: "<<nroma<<endl;
			system("PAUSE");
		}
	}
	if(modalidad==9){//cerrar el programa
		separar();
		intermitentewon("Cerrando el programa\n");
		for(int g=0;g<20;g++){
			Sleep(250);
			cout<<".";
		}
		cerrar=true;
	}
	if(modalidad==3){//modalidad clasica por zonas (de  sets de 10)
		zonas=true;
		zonaset=10;
		nzonas=npalabras/zonaset +1;
		separar();
		intermitentewon("Numero de palabras: ");cout<<npalabras<<endl;
		intermitentewon("Numero de zonas: ");cout<<nzonas<<endl;
		intermitente("Seleccion de zona:");
		cin>>seleczona;
		
		for(int npartida=0;npartida<5;npartida++){//cinco palabras)
			selecpalabra(); //seleccionar palabra y guardarla en seleckanji y selecromaji
			
			/*
			ESQUEMA CAMBIAR REPETIDOS
			
			bool cmprpt=comprobarrepetidos(de 0 a npartida);
			while(cmprpt==true){
			selecpalabra();
			intento[npartida]=aleatorio;
			cmprpt=comprobarrepetidos();
			}
			*/
			intento[npartida]=aleatorio;
			bool cmprpt=comprobarrepetidos(npartida);
			if(cmprpt==true){
				while(cmprpt==true){
					selecpalabra();
					intento[npartida]=aleatorio;
					cmprpt=comprobarrepetidos(npartida);				
				}
			}
			char respuesta[]="Garbage";
			bool fallo=true;int iterador=0;
			while(fallo==true){
				Sleep(500);
				separar();
				intermitentewon("Puntos: ");cout<<puntos<<endl;
				intermitentewon("Fallos: ");cout<<fallos<<endl;
				//pide respuesta y la guarda
				intermitente("\nEscriba la lectura de esta palabra en romaji:");
				intermitente(seleckanji);
				intermitente("\nRespuesta: ");scanf("%s",respuesta);
				//comprueba si respuesta es correcta
				bool iguales=true;
				for(int i=0;i<strlen(respuesta);i++){
					if(respuesta[i]!=selecromaji[i]){
						iguales=false;
					}
				}
				int mal=0;
				for(int i=0;i<strlen(respuesta);i++){
					if(respuesta[i]==finalizar[i]){
						mal++;
					}
					if(mal==9){
						fin=true;
					}
					else{
						fin=false;
					}
				}
				if(fin==true){fallo=false;npartida=5;cerrar=true;}
				if(iguales==true&&strlen(respuesta)==posteriorr-anteriorr-1){
					system("color 0a");
					//sonido
					sf::SoundBuffer buffer;
					if (!buffer.loadFromFile("Acierto.wav")){
						intermitente("\nError de audio");
					}
					sf::Sound sound;
					sound.setBuffer(buffer);
					sound.play();
					
					fallo=false;intermitente("\nCorrecto!\n");puntos++;Sleep(750);
					system("color 07");
				}else{
					if(iterador!=4){
						system("color 0c");
						//sonido
						sf::SoundBuffer buffer;
						if (!buffer.loadFromFile("Fallo.wav")){
							intermitente("\nError de audio");
						}
						sf::Sound sound;
						sound.setBuffer(buffer);
						sound.play();
					
						intermitente("Incorrecto, intentelo de nuevo\n");iterador++;fallos++;Sleep(2500);
						system("color 07");
					}
					else{
						system("color 0c");
						//sonido
						sf::SoundBuffer buffer;
						if (!buffer.loadFromFile("Fallo.wav")){
							intermitente("\nError de audio");
						}
						sf::Sound sound;
						sound.setBuffer(buffer);
						sound.play();
					
						intermitentewon("Incorrecto, la respuesta correcta era: ");intermitente(selecromaji);fallos++;iterador++;fallo=false;Sleep(1000);
						system("color 07");
						}	
				}
			}intermitente("Continuemos...");
			//reinicia el estado de seleckanji,  selecromaji y respuesta
			for(int gn=0;gn<strlen(seleckanji); gn++){
				seleckanji[gn]=' ';
			}
			for(int gn=0;gn<strlen(selecromaji); gn++){
				selecromaji[gn]=' ';
			}
			for(int gn=0;gn<strlen(respuesta); gn++){
				respuesta[gn]=' ';
			}
		}
		Sleep(500);
		separar();
		intermitentewon("\nPuntos finales: ");cout<<puntos<<endl;
		intermitentewon("\nFallos totales: ");cout<<fallos<<endl;
		if(fallos>14){
			system("color 0c");
			intermitente("Recomendamos estudiar estas palabras, ya que tiene mas de 15 fallos.");
			system("color 07");
		}
		if(fallos==0){
			//sonido
			sf::SoundBuffer buffer;
			if (!buffer.loadFromFile("Felicitaciones.wav")){
				intermitente("\nError de audio");
			}
			sf::Sound sound;
			sound.setBuffer(buffer);
			sound.play();
			intermitente("\nIncreible, sin fallos!");Sleep(2500);
		}
		if(fin==false){
		system("PAUSE");
		}
	}
	if(modalidad==4){//modalidad infinita por zonas (de sets de 50)
		zonas=true;
		zonaset=50;
		nzonas=npalabras/zonaset +1;
		separar();
		intermitentewon("Numero de palabras: ");cout<<npalabras<<endl;
		intermitentewon("Numero de zonas: ");cout<<nzonas<<endl;
		intermitente("Seleccion de zona:");
		cin>>seleczona;
		
		puntos=9;
		while(puntos>0){//mientras tengas puntos
			Sleep(500);
			separar();
			selecpalabra(); //seleccionar palabra y guardarla en seleckanji y selecromaji
			char respuesta[]="Garbage";
			intermitentewon("Puntos: ");cout<<puntos<<endl;
			intermitente("Escriba la lectura de esta palabra en romaji:");
			intermitente(seleckanji);
			intermitente("\nRespuesta: ");scanf("%s",respuesta);
			//comprueba si respuesta es correcta
			bool iguales=true;
			for(int i=0;i<strlen(respuesta);i++){
				if(respuesta[i]!=selecromaji[i]){
					iguales=false;
				}
			}
			int mal=0;
			for(int i=0;i<strlen(respuesta);i++){
				if(respuesta[i]==finalizar[i]){
					mal++;
				}
				if(mal==9){
					fin=true;
				}
				else{
					fin=false;
				}
			}
			if(fin==true){puntos=0;cerrar=true;}
			if(iguales==true&&strlen(respuesta)==posteriorr-anteriorr-1){
				system("color 0a");
				//sonido
				sf::SoundBuffer buffer;
				if (!buffer.loadFromFile("Acierto.wav")){
					intermitente("\nError de audio");
				}
				sf::Sound sound;
				sound.setBuffer(buffer);
				sound.play();
					
				intermitente("\nCorrecto!\n");puntos++;
				system("color 07");
			}else{
				
				system("color 0c");
				//sonido
				sf::SoundBuffer buffer;
				if (!buffer.loadFromFile("Fallo.wav")){
					intermitente("\nError de audio");
				}
				sf::Sound sound;
				sound.setBuffer(buffer);
				sound.play();
					
				intermitentewon("Incorrecto, la respuesta correcta era: ");
				intermitente(selecromaji);
				system("color 07");
				if(fin==false){
				system("PAUSE");
				}
				puntos=puntos-3;
			}
			if(puntos%10==0&&puntos!=10){
				if(puntosanteriores!=puntos&&puntos>puntosanteriores){
					separar();
					//sonido
					sf::SoundBuffer buffer;
					if (!buffer.loadFromFile("Felicitaciones.wav")){
						intermitente("\nError de audio");
					}
					sf::Sound sound;
					sound.setBuffer(buffer);
					sound.play();
					
					intermitente("Increible! Mira cuantos puntos tienes!");
				}
				puntosanteriores=puntos;
			}
			//reinicia el estado de seleckanji,  selecromaji y respuesta
			for(int gn=0;gn<strlen(seleckanji); gn++){
				seleckanji[gn]=' ';
			}
			for(int gn=0;gn<strlen(selecromaji); gn++){
				selecromaji[gn]=' ';
			}
			for(int gn=0;gn<strlen(respuesta); gn++){
				respuesta[gn]=' ';
			}
		}
		separar();
		intermitente("Lamentablemente, se ha quedado sin puntos (Game Over)");
	}
}
}
void separar(){
	int it=0;
	while(it<10){
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";it++;
	}
}
void intermitente(char frase[]){
	int longitud;
	longitud=strlen(frase);
	for(int i=0;i<=longitud;i++){cout<<frase[i];Sleep(25);}
	cout<<endl;
}
void intermitentewon(char frase[]){
	int longitud;
	longitud=strlen(frase);
	for(int i=0;i<=longitud;i++){cout<<frase[i];Sleep(25);}
}
void definsup(){
	superior=npalabras-zonaset*(seleczona-1);
	inferior=superior-zonaset;
	if(inferior<1){
		inferior=1;
	}
}
bool comprobarrepetidos(int partida){
	bool repite=false;
	if(partida<5&&partida!=0){
		for(int a=1;a<partida+1;a++){
			for(int b=0;b<a;b++){
				if(intento[a]==intento[b]){
					repite=true;
				}
			}
		}
	}else{
		if(partida!=0){
		cout<<"ERROR EN FUNCION COMPROBARREPETIDOS\npartida >=5\n";Sleep(5000);
		repite=true;
		}
	}
	return repite;
}


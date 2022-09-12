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

Dos modalidades, clásico e infinito

(Clásico)
Cinco palabras, cinco intentos por palabra

(Infinito)
Palabras infinitas, un punto por palabra, cada palabra errónea quita 3 puntos
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
	v1.3.3  agpal canciones up to mahiru no tsuki akari (‚»‚ê‚Í¬‚³‚ÈŒõ‚Ì‚æ‚¤‚ÈA‚Ç‚¤‚¹–³‚­‚È‚é‚¾‚¯A•‚‹C‚Í”Æßsˆ×A”½–Ê‹³tA^’‹‚ÌŒ–¾‚©‚èj 
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
//			 "ˆÃˆÅ+”Ş•û+‚Ş+•Ô+–j+‹·ŠÔ+›s‚Ş+•‚Å‚é+”÷‚©+‹P‚«+“±‚­+â‚µ‚¢+–„‚à‚ê‚é+•sv‹c+–µ‚+”Y‚Ş+”w•‰‚¤+«Ši+lŠi+Š‘F+“¯—Ş+—§ê+•ğ‚ê‚é+ˆ§‚¤+Œ©›‚ê‚é+•º‘à+‰æ–Ê+ˆÌ‚¢+•s‰õ+‘k‚é+Œ³X+S‚é+•ö‚ê‚é+•½“™+Œ™ˆ«+¦‚İ+‹ğ’s+— Ø‚è+–À‚¤+‘f“G+ŠyŸ+—~’£‚é+M†+‰¿’l+•‚‹C+•Ù‰ğ+”ƒ–Œ+˜M‚Ô+ŒãˆâÇ+–‘O+”¼’[+’[+“à–Ê+—‘z+–O‚«+¹“i+Šˆ×+Œå‚é+ˆø‚«Š·‚¦‚é+X¶+”‚®+“{‚è+û‚Ü‚é+”l‚é+•s’å•…‚ê‚é+Œ‹‰Ê+‘‚·+‘Ï‚¦‚é+ŸT•®+—H‚©+—Z‚¯‚é+—•+U‚é+œª‚Ş+‘Ì‰·+—n‚¯‚é+Ÿø‚Ş+“rØ‚ê‚é+Œ®+uŠÔ+‰÷‚¢+–‚¿‚é+Œ‡‚¯‚é+’Ô‚¶‚é+–Ø—§+ü˜H+‰ˆ‚¤+•É—+Š‚¤+Šú‘Ò+~‚è”G‚Â+‘‰‚¹‚é+‰˜‚ê‚é+Šñ‚é+—h‚ê‚é+Ó‚é+‘‚¦‚é+“¥‚Ş+‘¾‚é+‚²——‚É‚È‚é+‰^‚Ô+•¥‚¤+—â‚¦‚é+Œõ‚é+ˆø‚Á‰z‚·+E‚¤+–J‚ß‚é+‹F‚é+‹}‚®+’¸‚­+’v‚·+Šš‚Ş+•Ğ•t‚¯‚é+Ÿ‚Â+•é‚ê‚é+Q‚é+‰ñ‚é+¢‚µã‚ª‚é+–ß‚é+Œ}‚¦‚é+Œü‚©‚¤+“Š‚°‚é+’¼‚é+¡‚é+Šµ‚ê‚é+–Â‚é+“¦‚°‚é+—‚é+c‚é+æ‚èŠ·‚¦‚é+”G‚ê‚é+“h‚é+“‚Ş+‹Á‚­+‹N‚±‚·+’x‚ê‚é+‘—‚é+Ü‚ê‚é+Ü‚é+‹Â‚é+’T‚·+·‚µã‚°‚é+‘›‚®+G‚é+¶‚é+’²‚×‚é+¶‚¶‚é+ŠŠ‚é+Ï‚Ş+i‚Ş+Ì‚Ä‚é+‘«‚è‚é+‘«‚·+Œš‚Ä‚é+q‚Ë‚é+è“`‚¤+“Í‚¯‚é+æ‚è‘Ö‚¦‚é+‘±‚­+‘±‚¯‚é+•ß‚Ü‚¦‚é+’Ğ‚¯‚é+˜A‚ê‚é+’Ş‚é+“`‚¦‚é+A‚¦‚é+f‚¤+‘Å‚Â+ˆÚ‚é+Ê‚·+•Ê‚ê‚é+•¦‚©‚·+•¦‚­+Š„‚ê‚é+Ä‚¯‚é+Ä‚­+‘c•ƒ+‘²‹Æ+‘Š’k+…“¹+…‰j+‹÷+»+‘Ş‰@+’I+’a¶+ô+è‘Ü+’š”J+“K“–+“W——‰ï+›+“r’†+“Á‹}+°‰®+“s‡+˜r+ó•t+‰^“]è+— +Š„‡+—\K+—\’è+—p+—pˆÓ+—p–+—\–ñ+“’+w—Ö+c”O+`+–¡‘X+“s+ŒÎ+–Ø–È+’+¶+“ñŠKŒš‚Ä+lŒ`+“õ‚¢+A+‚¨ì‚³‚ñ+‰®ã+‚¨Õ‚è+‚¨Œ©•‘‚¢+‚¨“yY+‰Ÿ‚µ“ü‚ê+‚¨‘î+e+—â–[+—ğj+—˜—p+—¯ç+—·ŠÙ+â+Y‹Æ+­¡+¶–½+¶Y+¼—m+ü+”w’†+í‘ˆ+Ğ’·+Ğ‰ï+s+‡+d•û+Œ±+“‡+s–¯+•i•¨+V•·Ğ+eØ+¸”s+‰º’…+H—¿•i+Ğ‰î+«—ˆ+ï–¡+KŠµ+‘c•ê+ˆê¶Œœ–½+…+š+–ŒÌ+_Ğ+lŒû+«“T+\•ª+_“¹+‰Û’·+‰ÈŠw+‹¾+‰ï‹c+‰ï‹cº+‰ïê+‰ï˜b+‰Î–+ŠiD+”¯+‰Æ“à+ŠÅŒì•w+ŠÖŒW+–Ñ+‰ö‰ä+Œv‰æ+ŒoŒ±+Œx@+ŒoÏ+Œ©•¨+Œ¤‹†+Œ¤‹†º+ŒiF+‹@‰ï+‹ßŠ+Œ¦+‹Gß+‹DÔ+‹K‘¥+Z’·+u“°+xŠO+u‹`+H‹Æ+Hê+Œö–±ˆõ+‚“™ŠwZ+Œğ’Ê+‹³ˆç+‹³‰ï+‹»–¡+‹£‘ˆ+‹}s+–Ÿ‰æ+^‚ñ’†+ü‚è+ˆ¥A+–¡+Ô‚ñ–V+ˆÄ“à+”{+”Ô‘g+êŠ+”üpŠÙ+–fˆÕ+•”’·+•¶Šw+•¶‰»+•¶–@+’n—+’ˆÓ+’Ë+’“Ôê+‘å‘Ì+’g–[+’j«+“d•ñ+“d“”+“D–_+“®•¨‰€+“¹‹ï+}+‰“—¶+•s•Ö+‘D+M+•z’c+•’Ê+Œ´ˆö+‰ºh+‹Zp+‹ï‡+”qŒ©+•ˆãÒ+‰ÔŒ©+”½‘Î+”­‰¹+—Ñ+•E+”òsê+’‹ŠÔ+’‹‹x‚İ+‹v‚µ‚Ô‚è+–|–ó+¯+–@—¥+•ú‘—+ˆÈŠO+ˆãŠw+ˆÈã+ˆÈ‰º+ˆÈ“à+“cÉ+‘İ‚·+‹È‚ª‚é+–‚­+•À‚×‚é+’š“x+—§”h+×‚¢+Œy‚¢+‰·‚¢+”Ï‚¢+c+Œ{“÷+ˆê“ú+ã’…+”ª•S‰®+—m•+—[•û+—[”Ñ+‚¨• +ˆêğ”N+˜L‰º+ì•¶+”wL+‘|œ+‘òR+g’ƒ+Œğ·“_+ŒC+–œ”N•M+–å+˜Z“ú+‚¨„‚è‚³‚ñ+20Î+20“ú+‰É+’r+šˆø+«‘+Ø•„+‹i’ƒ“X+–k+‰”•M+••“›+‹“û+—t‘+ŠDM+•@+‘ågŠÙ+ŒÌá+’Ê‚é+’l’i+—¼•û+“ü‰@+—L–¼+Šì‚Ô+—¯Šw+–ìØ+“Á•Ê+•ûŒü+—¬‚ê‚é+ô‘ó+Š£‚­+—â‚ß‚é+’…‘Ö‚¦‚é+ÎŒ²+–ì‹…+’‹H+’©H+–°‚é+¼+“Œ+“ì+—[H+—ã‚Ü‚·+—Ü+Eê+‘‹+‰Ÿ‚·+“üŠw+ŒË+’Ê‚è+•v•w+—«+”M+—x‚é+Œú‚³+”é–§+’Ê‚¤+‹‹—¿+×‚©‚¢+Œ’N+¬Ñ+‹³‰È‘+‹³º+‹³t+‡Ši+•Ç+ˆç‚Ä‚é+“|‚ê‚é+ü‚é+‰º‚°‚é+‘¡‚é+–K‚Ë‚é+ŒºŠÖ+’·’j+ˆÊ’u+ŒŠ+ŠCŠİ+G+¬à+•I+–+“¹˜H+l‚ÂŠp+‹È‚ª‚èŠp+Œx@+‰Æ’ë+ŠúŠÔ+ŒoŒ±+’nk+èp+‰Î+‘Û+’ñˆÄ+––±Š+‹³ö+ŒÅ‚¢+‰üDŒû+‰–+‚¨’Ş‚è+–¼š+•Ô–+•¡G+Š‰‚­+ˆÓŒ©+”–‚¢+»“œ+—X•Ö‹Ç+ZŠ+—Á‚µ‚¢+–¼+Šá‹¾+Š“+Œµ‚µ‚¢+‹Î‚ß‚é+“ö‚â‚©+ŠÉ‚¢+•r+İ–û+’ƒ˜q+•œK+”û+•—×–ò+ğ–é+—¬s‚é+”¼Œ+Œ–‰Ü+‘Iè+‹A‘+€”õ+“Á‚É+‚¨j‚¢+•G+•Ó‚è+–¾Œã“ú+‹”N+Ú‚¹‚é+˜+”‘‚Ü‚é+Š‰‚­+ñ"
char kanji[]="ˆÃˆÅ+”Ş•û+‚Ş+•Ô+–j+‹·ŠÔ+›s‚Ş+•‚Å‚é+”÷‚©+‹P‚«+“±‚­+â‚µ‚¢+–„‚à‚ê‚é+•sv‹c+–µ‚+”Y‚Ş+”w•‰‚¤+«Ši+lŠi+Š‘F+“¯—Ş+—§ê+•ğ‚ê‚é+ˆ§‚¤+Œ©›‚ê‚é+•º‘à+‰æ–Ê+ˆÌ‚¢+•s‰õ+‘k‚é+Œ³X+S‚é+•ö‚ê‚é+•½“™+Œ™ˆ«+¦‚İ+‹ğ’s+— Ø‚è+–À‚¤+‘f“G+ŠyŸ+—~’£‚é+M†+‰¿’l+•‚‹C+•Ù‰ğ+”ƒ–Œ+˜M‚Ô+ŒãˆâÇ+–‘O+”¼’[+’[+“à–Ê+—‘z+–O‚«+¹“i+Šˆ×+Œå‚é+ˆø‚«Š·‚¦‚é+X¶+”‚®+“{‚è+û‚Ü‚é+”l‚é+•s’å•…‚ê‚é+Œ‹‰Ê+‘‚·+‘Ï‚¦‚é+ŸT•®+—H‚©+—Z‚¯‚é+—•+U‚é+œª‚Ş+‘Ì‰·+—n‚¯‚é+Ÿø‚Ş+“rØ‚ê‚é+Œ®+uŠÔ+‰÷‚¢+–‚¿‚é+Œ‡‚¯‚é+’Ô‚¶‚é+–Ø—§+ü˜H+‰ˆ‚¤+•É—+Š‚¤+Šú‘Ò+~‚è”G‚Â+‘‰‚¹‚é+‰˜‚ê‚é+Šñ‚é+—h‚ê‚é+Ó‚é+‘‚¦‚é+“¥‚Ş+‘¾‚é+‚²——‚É‚È‚é+‰^‚Ô+•¥‚¤+—â‚¦‚é+Œõ‚é+ˆø‚Á‰z‚·+E‚¤+–J‚ß‚é+‹F‚é+‹}‚®+’¸‚­+’v‚·+Šš‚Ş+•Ğ•t‚¯‚é+Ÿ‚Â+•é‚ê‚é+Q‚é+‰ñ‚é+¢‚µã‚ª‚é+–ß‚é+Œ}‚¦‚é+Œü‚©‚¤+“Š‚°‚é+’¼‚é+¡‚é+Šµ‚ê‚é+–Â‚é+“¦‚°‚é+—‚é+c‚é+æ‚èŠ·‚¦‚é+”G‚ê‚é+“h‚é+“‚Ş+‹Á‚­+‹N‚±‚·+’x‚ê‚é+‘—‚é+Ü‚ê‚é+Ü‚é+‹Â‚é+’T‚·+·‚µã‚°‚é+‘›‚®+G‚é+¶‚é+’²‚×‚é+¶‚¶‚é+ŠŠ‚é+Ï‚Ş+i‚Ş+Ì‚Ä‚é+‘«‚è‚é+‘«‚·+Œš‚Ä‚é+q‚Ë‚é+è“`‚¤+“Í‚¯‚é+æ‚è‘Ö‚¦‚é+‘±‚­+‘±‚¯‚é+•ß‚Ü‚¦‚é+’Ğ‚¯‚é+˜A‚ê‚é+’Ş‚é+“`‚¦‚é+A‚¦‚é+f‚¤+‘Å‚Â+ˆÚ‚é+Ê‚·+•Ê‚ê‚é+•¦‚©‚·+•¦‚­+Š„‚ê‚é+Ä‚¯‚é+Ä‚­+‘c•ƒ+‘²‹Æ+‘Š’k+…“¹+…‰j+‹÷+»+‘Ş‰@+’I+’a¶+ô+è‘Ü+’š”J+“K“–+“W——‰ï+›+“r’†+“Á‹}+°‰®+“s‡+˜r+ó•t+‰^“]è+— +Š„‡+—p+—pˆÓ+—p–+“’+w—Ö+c”O+`+–¡‘X+“s+ŒÎ+–Ø–È+’+¶+“ñŠKŒš‚Ä+lŒ`+“õ‚¢+A+‚¨ì‚³‚ñ+‰®ã+‚¨Õ‚è+‚¨Œ©•‘‚¢+‚¨“yY+‰Ÿ‚µ“ü‚ê+‚¨‘î+e+—â–[+—ğj+—˜—p+—¯ç+—·ŠÙ+â+Y‹Æ+­¡+¶–½+¶Y+¼—m+ü+”w’†+í‘ˆ+Ğ’·+Ğ‰ï+s+‡+d•û+Œ±+“‡+s–¯+•i•¨+V•·Ğ+eØ+¸”s+‰º’…+H—¿•i+Ğ‰î+«—ˆ+ï–¡+KŠµ+‘c•ê+ˆê¶Œœ–½+…+š+–ŒÌ+_Ğ+lŒû+«“T+\•ª+_“¹+‰Û’·+‰ÈŠw+‹¾+‰ï‹c+‰ï‹cº+‰ïê+‰ï˜b+‰Î–+ŠiD+”¯+‰Æ“à+ŠÅŒì•w+ŠÖŒW+–Ñ+‰ö‰ä+Œv‰æ+ŒoŒ±+Œx@+ŒoÏ+Œ©•¨+Œ¤‹†+Œ¤‹†º+ŒiF+‹@‰ï+‹ßŠ+Œ¦+‹Gß+‹DÔ+‹K‘¥+Z’·+u“°+xŠO+u‹`+H‹Æ+Hê+Œö–±ˆõ+‚“™ŠwZ+Œğ’Ê+‹³ˆç+‹³‰ï+‹»–¡+‹£‘ˆ+‹}s+–Ÿ‰æ+^‚ñ’†+ü‚è+ˆ¥A+–¡+Ô‚ñ–V+ˆÄ“à+”{+”Ô‘g+êŠ+”üpŠÙ+–fˆÕ+•”’·+•¶Šw+•¶‰»+•¶–@+’n—+’ˆÓ+’Ë+’“Ôê+‘å‘Ì+’g–[+’j«+“d•ñ+“d“”+“D–_+“®•¨‰€+“¹‹ï+}+‰“—¶+•s•Ö+‘D+M+•z’c+•’Ê+Œ´ˆö+‰ºh+‹Zp+‹ï‡+”qŒ©+•ˆãÒ+‰ÔŒ©+”½‘Î+”­‰¹+—Ñ+•E+”òsê+’‹ŠÔ+’‹‹x‚İ+‹v‚µ‚Ô‚è+–|–ó+¯+–@—¥+•ú‘—+ˆÈŠO+ˆãŠw+ˆÈã+ˆÈ‰º+ˆÈ“à+“cÉ+‘İ‚·+‹È‚ª‚é+–‚­+•À‚×‚é+’š“x+—§”h+×‚¢+Œy‚¢+‰·‚¢+”Ï‚¢+c+Œ{“÷+ˆê“ú+ã’…+”ª•S‰®+—m•+—[•û+—[”Ñ+‚¨• +ˆêğ”N+˜L‰º+ì•¶+”wL+‘|œ+‘òR+g’ƒ+Œğ·“_+ŒC+–œ”N•M+–å+˜Z“ú+‚¨„‚è‚³‚ñ+20Î+20“ú+‰É+’r+šˆø+«‘+Ø•„+‹i’ƒ“X+–k+‰”•M+••“›+‹“û+—t‘+ŠDM+•@+‘ågŠÙ+ŒÌá+’Ê‚é+’l’i+—¼•û+“ü‰@+—L–¼+Šì‚Ô+—¯Šw+–ìØ+“Á•Ê+•ûŒü+—¬‚ê‚é+ô‘ó+Š£‚­+—â‚ß‚é+’…‘Ö‚¦‚é+ÎŒ²+–ì‹…+’‹H+’©H+–°‚é+¼+“Œ+“ì+—[H+—ã‚Ü‚·+—Ü+Eê+‘‹+‰Ÿ‚·+“üŠw+ŒË+’Ê‚è+•v•w+—«+”M+—x‚é+Œú‚³+”é–§+’Ê‚¤+‹‹—¿+×‚©‚¢+Œ’N+¬Ñ+‹³‰È‘+‹³º+‹³t+‡Ši+•Ç+ˆç‚Ä‚é+“|‚ê‚é+ü‚é+‰º‚°‚é+‘¡‚é+–K‚Ë‚é+ŒºŠÖ+’·’j+ˆÊ’u+ŒŠ+ŠCŠİ+G+¬à+•I+–+“¹˜H+l‚ÂŠp+‹È‚ª‚èŠp+Œx@+‰Æ’ë+ŠúŠÔ+ŒoŒ±+’nk+èp+‰Î+‘Û+’ñˆÄ+––±Š+‹³ö+ŒÅ‚¢+‰üDŒû+‰–+‚¨’Ş‚è+–¼š+•Ô–+•¡G+Š‰‚­+ˆÓŒ©+”–‚¢+»“œ+—X•Ö‹Ç+ZŠ+—Á‚µ‚¢+–¼+Šá‹¾+Š“+Œµ‚µ‚¢+‹Î‚ß‚é+“ö‚â‚©+ŠÉ‚¢+•r+İ–û+’ƒ˜q+•œK+”û+•—×–ò+ğ–é+—¬s‚é+”¼Œ+Œ–‰Ü+‘Iè+‹A‘+€”õ+“Á‚É+‚¨j‚¢+•G+•Ó‚è+–¾Œã“ú+‹”N+Ú‚¹‚é+˜+”‘‚Ü‚é+Š‰‚­+ñ";
char seleckanji[100];//palabra seleccionada
char seleckanjianterior[100];
//lista de palabras en romaji 
char romaji[]="kurayami kanata kizamu haguruma hoho hazama haramu naderu kasuka kagayaki michibiku sabishii umoreru fushigi mujun nayamu seou seikaku jinkaku shosen dourui tachiba akireru au mitoreru heitai gamen erai fukai sakanoboru motomoto tsumeru kuzureru byoudou keno urami guchi uragiri mayou suteki rakushou yokubaru shingou kachi uwaki benkai suukagetsu moteasobu kouishou jizen hanpa hashi naimen risou aki shitto shoi satoru hikikaeru kousei hagu ikari osamaru nonoshiru futekusareru kekka masu taeru uppun kasuka tokeru ai furu kajikamu taion tokeru nijimu togireru kagi shunkan kui michiru kakeru tojiru kodachi senro sou hekiraku kanau kitai furisobotsu yaseru yogoreru yoru yureru ayamaru fueru fumu futoru goranninaru hakobu harau hieru hikaru hikkosu hirou homeru inoru isogu itadaku itasu kamu katadzukeru katsu kureru mairu mawaru meshiagaru modoru mukaeru mukau nageru naoru naoru nareru naru nigeru niru nokoru norikaeru nureru nuru nusumu odoroku okosu okureru okuru oreru oru ossharu sagasu sashiageru sawagu sawaru shikaru shiraberu shoujiru suberu sumu susumu suteru tariru tasu tateru tazuneru tetsudau todokeru torikaeru tsudzuku tsudzukeru tsukamaeru tsukeru tsureru tsuru tsutaeru ueru ukagau utsu utsuru utsusu wakareru wakasu waku wareru yakeru yaku sofu sotsugyou soudan suidou suiei sumi suna taiin tana tanjou tatami tebukuro teinei tekitou tenrankai tera tochuu tokkyuu tokoya tsugou ude uketsuke untenshu ura wariai you youi youji yu yubiwa zannen minato miso miyako mizuumi momen mushi nama nikaidate ningyou nioi nodo ojousan okujou omatsuri omimai omiyage oshiire otaku oya reibou rekishi riyou rusu ryokan saka sangyou seiji seimei seisan seiyou sen senaka sensou shachou shakai shi shiai shikata shiken shima shimin shinamono shinbunsha shinsetsu shippai shitagi shokuryouhin shoukai shourai shumi shuukan sobo isshoukenmei ito ji jiko jinja jinkou jiten juubun juudou kachou kagaku kagami kaigi kaigishitsu kaijou kaiwa kaji kakkou kami kanai kangofu kankei ke kega keikaku keiken keisatsu keizai kenbutsu kenkyuu kenkyuushitsu keshigi kikai kinjo kinu kisetsu kisha kisoku kouchou koudou kougai kougi kougyou koujou koumuin koutougakkou koutsuu kyouiku kyoukai kyoumi kyousou kyuukou manga mannaka mawari aisatsu aji akanbou annai bai bangumi basho bijutsukan boueki buchou bungaku bunka bunpou chiri chuui chuusha chuushajou daitai danbou dansei denpou dentou dorobou doubutsuen dougu eda enryo fuben fune fune futon futsuu genin geshuku gijutsu guai haiken haisha hanami hantai hatsuon hayashi hige hikoujou hiruma hiruyasumi hisashiburi honyaku hoshi houritsu housou igai igaku ijou ika inai inaka kasu magaru migaku naraberu choudo rippa hosoi karui nurui urusai tate toriniku tsuitachi uwagi yaoya youfuku yuugata yuuhan onaka ototoshi rouka sakubun sebiro souji takusan koucha kousaten kutsu mannenhitsu mon muika omawarisan hatachi hatsuka hima ike jibiki jisho kippu kissaten kita enpitsu fuutou gyuunyuu hagaki haizara hana taishikan koshou tooru nedan ryouhou nyuuin yuumei yorokobu ryuugaku yasai tokubetsu houkou nagareru sentaku kawaku sameru kigaeru sekken yakyuu chuushoku choushoku nemuru nishi higashi minami yuushoku hagemasu namida shokuba mado osu nyuugaku to toori fuufu josei netsu odoru atsusa himitsu kayou kyuuryou komakai kenkou seiseki kyoukasho kyoushitsu kyoushi goukaku kabe sodateru taoreru kazaru sageru okuru tazuneru genkan chounan ichi ana kaigan zasshi shousetsu hiji makura douro yotsukado magarikado keisatsu katei kikan keiken jishin shujutsu yakedo kokusai teian jimusho kyouju katai kaisatsuguchi shio otsuri myouji henji fukuzatsu kawaku iken usui satou yuubinkyoku juusho suzushii shimei megane kaban kibishii tsutomeru nigiyaka yurui bin shouyu chawan fukushuu mayu kazegusuri sakuya hayaru hantsuki kenka senshu kikoku junbi tokuni oiwai hiza atari myougonichi kyonen noseru koshi tomaru kawaku ñ";
char selecromaji[100];//romaji seleccionado
char selecromajianterior[100];
int longitud_kanji,longitud_romaji;//longitud de la lista (caracteres)

int npalabras=0,nroma=0,aleatorio;//numero de palabras,espacio aleatorio,
int anteriork, posteriork,anteriorr, posteriorr;// posición anterior, posición posterior para kanji k y romaji r
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
	intermitentewon("Gracias por jugar!\nŠ¿šA“Ç‚ß‚Ü‚·‚©B (Kanji, yomemasu ka?) v");intermitente(version);

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
	intermitentewon("Š¿šA“Ç‚ß‚Ü‚·‚©B (Kanji, yomemasu ka?) v");intermitente(version);
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


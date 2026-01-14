# rtl_433

rtl_433 (isme rağmen) genel bir veri alıcısıdır, ağırlıklı olarak 433.92 MHz, 868 MHz (SRD), 315 MHz, 345 MHz ve 915 MHz ISM bantları için.

Resmi kaynak kod https://github.com/merbanan/rtl_433/ deposunda bulunmaktadır.
Daha fazla belge ve ilgili projeler için https://triq.org/ sitesine bakın.

[RTL-SDR](https://github.com/osmocom/rtl-sdr/) ve/veya [SoapySDR](https://github.com/pothosware/SoapySDR/) ile çalışır.

Aktif olarak test edilen ve desteklenenler: Realtek RTL2832 tabanlı DVB dongle'leri (RTL-SDR kullanarak) ve LimeSDR ([LimeSDR USB](https://www.crowdsupply.com/lime-micro/limesdr) ve [LimeSDR mini](https://www.crowdsupply.com/lime-micro/limesdr-mini) mühendislik numuneleri [MyriadRf](https://myriadrf.org/) tarafından nazikçe sağlanmıştır), PlutoSDR, HackRF One (SoapySDR sürücüleri kullanarak) ve SoapyRemote.

![rtl_433 ekran görüntüsü](./docs/screenshot.png)

## Derleme / Kurulum

rtl_433 taşınabilir C (C99 standardı) ile yazılmıştır ve Linux (ayrıca gömülü), MacOS ve Windows sistemlerinde derlendiği bilinmektedir.
Eski derleyiciler ve araç zincirleri temel bir hedef olarak desteklenmektedir.
Düşük kaynak tüketimi ve çok az bağımlılık, rtl_433'ün (yeniden amaçlandırılmış) yönlendiriciler gibi gömülü donanım üzerinde çalışmasını sağlar.
32-bit i686 ve 64-bit x86-64 sistemler ve (gömülü) ARM, Raspberry Pi ve PlutoSDR gibi iyi desteklenir.

[BUILDING.md](docs/BUILDING.md) dosyasına bakın

Debian (sid) veya Ubuntu (19.10+) üzerinde, `apt-get install rtl-433` diğer dağıtımlar için https://repology.org/project/rtl-433/versions adresini kontrol edin

FreeBSD üzerinde, `pkg install rtl-433`.

MacOS üzerinde, `brew install rtl_433`.

rtl_433 içeren Docker görüntüleri [hertzg'in github sayfasında](https://github.com/hertzg/rtl_433_docker) mevcuttur.

## Desteklenmeyen sensörler için destek ekleme

[CONTRIBUTING.md](./docs/CONTRIBUTING.md) dosyasına bakın.

## Çalıştırma

    rtl_433 -h

```

  "rtl_433.conf" dosyası "./", XDG_CONFIG_HOME örn. "$HOME/.config/rtl_433/",
  SYSCONFDIR örn. "/usr/local/etc/rtl_433/" dizinlerinde aranır, ardından komut satırı argümanları sırayla işlenir.
		= Genel seçenekler =
  [-V] Sürüm bilgisini yazdır ve çık
  [-v] Ayrıntı seviyesini artır (birden fazla kullanılabilir).
       -v : ayrıntılı notice, -vv : ayrıntılı info, -vvv : debug, -vvvv : trace.
  [-c <yol>] Yapılandırma seçeneklerini bir dosyadan oku
		= Alıcı seçenekleri =
  [-d <RTL-SDR USB cihaz indeksi> | :<RTL-SDR USB cihaz seri numarası> | <SoapySDR cihaz sorgusu> | rtl_tcp | help]
  [-g <gain> | help] (varsayılan: auto)
  [-t <ayarlar>] SDR cihazına anahtar=değer ayarları listesi uygula
       örn. SoapySDR için -t "antenna=A,bandwidth=4.5M,rfnotch_ctrl=false"
       RTL-SDR için "direct_samp[=1]", "offset_tune[=1]", "digital_agc[=1]", "biastee[=1]" kullanın
  [-f <frekans>] Alma frekansı (varsayılan: 433920000 Hz)
  [-H <saniye>] Çoklu frekans yoklama için atlama aralığı (varsayılan: 600 saniye)
  [-p <ppm_hatası>] rtl-sdr alıcı frekans ofset hatasını düzelt (varsayılan: 0)
  [-s <örnekleme hızı>] Örnekleme hızını ayarla (varsayılan: 250000 Hz)
  [-D quit | restart | pause | manual] Giriş cihazı çalıştırma modu seçenekleri (varsayılan: quit).
		= Demodülatör seçenekleri =
  [-R <cihaz> | help] Sadece belirtilen cihaz kod çözme protokolünü etkinleştir (birden fazla kez kullanılabilir)
       Bir cihaz kod çözme protokolünü devre dışı bırakmak için negatif sayı belirtin (birden fazla kez kullanılabilir)
  [-X <spec> | help] Genel amaçlı bir kod çözücü ekleyin (tüm kod çözücüleri devre dışı bırakmak için -R 0 ekleyin)
  [-Y auto | classic | minmax] FSK darbe algılama modu.
  [-Y level=<dB seviyesi>] Darbeleri belirlemek için manuel algılama seviyesi (-1.0 ile -30.0 arası, 0=oto).
  [-Y minlevel=<dB seviyesi>] Darbeleri belirlemek için manuel minimum algılama seviyesi (-1.0 ile -99.0 arası).
  [-Y minsnr=<dB seviyesi>] Darbeleri belirlemek için minimum SNR (1.0 ile 99.0 arası).
  [-Y autolevel] Minimum seviyayı tahmini ortalama gürültüye göre otomatik ayarla.
  [-Y squelch] CPU yükünü azaltmak için tahmini gürültü seviyesinin altındaki çerçeveleri atla.
  [-Y ampest | magest] Genlik veya magnitüd seviyesi tahmin edicisi seçin.
		= Analiz/Hata ayıklama seçenekleri =
  [-A] Darbe Analizi. Darbe analizini ve kod çözme denemesini etkinleştir.
       Sadece analizör çıktısını istiyorsanız tüm kod çözücüleri -R 0 ile devre dışı bırakın.
  [-y <kod>] Etkin cihazlarla demodüle edilmiş test verilerinin kod çözülmesini doğrulayın (örn. "{25}fb2dd58")
		= Dosya G/Ç seçenekleri =
  [-S none | all | unknown | known] Sinyal otomatik kaydet. Her sinyal için bir dosya oluşturur.
       Not: Ham I/Q örneklerini kaydeder (uint8 pcm, 2 kanal). Test dosyası oluşturma için tercih edilen mod.
  [-r <dosya adı> | help] Verileri bir alıcı yerine giriş dosyasından oku
  [-w <dosya adı> | help] Veri akışını çıktı dosyasına kaydet ('-' örnekleri stdout'a döker)
  [-W <dosya adı> | help] Veri akışını çıktı dosyasına kaydet, mevcut dosyanın üzerine yaz
		= Veri çıktı seçenekleri =
  [-F log | kv | json | csv | mqtt | influx | syslog | trigger | rtl_tcp | http | null | help] Kodu çözülmüş çıktıyı verilen formatta üret.
       Çıktıyı dosyaya eklemek için :<dosya adı> kullanın (örn. -F csv:log.csv), varsayılan stdout.
       Syslog için ana bilgisayar/bağlantı noktası örn. -F syslog:127.0.0.1:1514 ile belirtin
  [-M time[:<seçenekler>] | protocol | level | noise[:<sn>] | stats | bits | help] Her çıktıya çeşitli meta veriler ekleyin.
  [-K FILE | PATH | <etiket> | <anahtar>=<etiket>] Her çıktı satırına genişletilmiş bir jeton veya sabit etiket ekleyin.
  [-C native | si | customary] Kodu çözülmüş çıktıda birimleri dönüştür.
  [-n <değer>] Alınacak örnek sayısını belirtin (her örnek bir I/Q çiftidir)
  [-T <saniye>] Çalıştırılacak saniye sayısını belirtin, ayrıca 12:34 veya 1h23m45s formatında
  [-E hop | quit] Başarılı olay(ları) çıkardıktan sonra Atlama/Çıkış
  [-h] Bu kullanım yardımını yazdır ve çık
       Daha fazla yardım için -d, -g, -R, -X, -F, -M, -r, -w veya -W'yi argüman olmadan kullanın



		= Desteklenen cihaz protokolleri =
    [01]  Silvercrest Uzaktan Kumanda
    [02]  Rubicson, TFA 30.3197 veya InFactory PT-310 Sıcaklık Sensörü
    [03]  Prologue, FreeTec NC-7104, NC-7159-675 sıcaklık sensörü
    [04]  Waveman Anahtar Verici
    [06]* ELV EM 1000
    [07]* ELV WS 2000
    [08]  LaCrosse TX Sıcaklık / Nem Sensörü
    [10]  Acurite 896 Yağmur Ölçer
    [11]  Acurite 609TXC Sıcaklık ve Nem Sensörü
    [12]  Oregon Scientific Hava Durumu Sensörü
    [13]* Mebus 433
    [14]* Intertechno 433
    [15]  KlikAanKlikUit Kablosuz Anahtar
    [16]  AlectoV1 Hava Durumu Sensörü (Alecto WS3500 WS4500 Ventus W155/W044 Oregon)
    [17]  Cardin S466-TX2
    [18]  Fine Offset Electronics, WH2, WH5, Telldus Sıcaklık/Nem/Yağmur Sensörü
    [19]  Nexus, FreeTec NC-7345, NX-3980, Solight TE82S, TFA 30.3209 sıcaklık/nem sensörü
    [20]  Ambient Weather F007TH, TFA 30.3208.02, SwitchDocLabs F016TH sıcaklık sensörü
    [21]  Calibeur RF-104 Sensör
    [22]  X10 RF
    [23]  DSC Güvenlik İletişimi
    [24]* Brennenstuhl RCS 2044
    [25]  Globaltronics GT-WT-02 Sensör
    [26]  Danfoss CFR Termostat
    [29]  Chuango Güvenlik Teknolojisi
    [30]  Genel Uzaktan Kumanda SC226x EV1527
    [31]  TFA-Twin-Plus-30.3049, Conrad KW9010, Ea2 BL999
    [32]  Fine Offset Electronics WH1080/WH3080 Hava Durumu İstasyonu
    [33]  WT450, WT260H, WT405H
    [34]  LaCrosse WS-2310 / WS-3600 Hava Durumu İstasyonu
    [35]  Esperanza EWS
    [36]  Efergy e2 classic
    [37]* Inovalley kw9015b, TFA Dostmann 30.3161 (Yağmur ve sıcaklık sensörü)
    [38]  Genel sıcaklık sensörü 1
    [39]  WG-PB12V1 Sıcaklık Sensörü
    [40]  Acurite 592TXR sıcaklık/nem, 592TX sıcaklık, 5n1, 3n1, Atlas hava istasyonu, 515 buzdolabı/dondurucu, 6045 yıldırım, 899 yağmur, 1190/1192 sızıntı
    [41]  Acurite 986 Buzdolabı / Dondurucu Termometresi
    [42]  HIDEKI TS04 Sıcaklık, Nem, Rüzgar ve Yağmur Sensörü
    [43]  Watchman Sonic / Apollo Ultrasonic / Beckett Rocket yakıt tankı monitörü
    [44]  CurrentCost Akım Sensörü
    [45]  emonTx OpenEnergyMonitor
    [46]  HT680 Uzaktan kumanda
    [47]  Conrad S3318P, FreeTec NC-5849-913 sıcaklık nem sensörü, ORIA WA50 ST389 sıcaklık sensörü
    [48]* Akhan 100F14 uzaktan anahtarsız giriş
    [49]  Quhwa
    [50]  OSv1 Sıcaklık Sensörü
    [51]  Proove / Nexa / KlikAanKlikUit Kablosuz Anahtar
    [52]  Bresser Thermo-/Hygro-Sensor 3CH
    [53]  Springfield Sıcaklık ve Toprak Nemi
    [54]  Oregon Scientific SL109H Uzaktan Termal Nem Sensörü
    [55]  Acurite 606TX / Technoline TX960 Sıcaklık Sensörü
    [56]  TFA havuz sıcaklık sensörü
    [57]  Kedsum Sıcaklık & Nem Sensörü, Pearl NC-7415
    [58]  Blyss DC5-UK-WH
    [59]  Steelmate TPMS
    [60]  Schrader TPMS
    [61]* LightwaveRF
    [62]* Elro DB286A Zil
    [63]  Efergy Optical
    [64]* Honda Araba Anahtarı
    [67]  Radiohead ASK
    [68]  Kerui PIR / İletişim Sensörü
    [69]  Fine Offset WH1050 Hava Durumu İstasyonu
    [70]  Honeywell Kapı/Pencere Sensörü, 2Gig DW10/DW11, RE208 tekrarlayıcı
    [71]  Maverick ET-732/733 BBQ Sensörü
    [72]* RF-tech
    [73]  LaCrosse TX141-Bv2, TX141TH-Bv2, TX141-Bv3, TX141W, TX145wsdth, (TFA, ORIA) sensör
    [74]  Acurite 00275rm,00276rm Sıcaklık/Nem opsiyonel prob ile
    [75]  LaCrosse TX35DTH-IT, TFA Dostmann 30.3155 Sıcaklık/Nem sensörü
    [76]  LaCrosse TX29IT, TFA Dostmann 30.3159.IT Sıcaklık sensörü
    [77]  Vaillant calorMatic VRT340f Merkezi Isıtma Kontrolü
    [78]  Fine Offset Electronics, WH25, WH32, WH32B, WN32B, WH24, WH65B, HP1000, Misol WS2320 Sıcaklık/Nem/Basınç Sensörü
    [79]  Fine Offset Electronics, WH0530 Sıcaklık/Yağmur Sensörü
    [80]  IBIS işaretçi
    [81]  Yağ Ultrasonik STANDARD FSK
    [82]  Citroen TPMS
    [83]  Yağ Ultrasonik STANDARD ASK
    [84]  Thermopro TP11 Termometre
    [85]  Solight TE44/TE66, EMOS E0107T, NX-6876-917
    [86]* Kablosuz Duman ve Isı Dedektörü GS 558
    [87]  Genel kablosuz hareket sensörü
    [88]  Toyota TPMS
    [89]  Ford TPMS
    [90]  Renault TPMS
    [91]  inFactory, nor-tec, FreeTec NC-3982-913 sıcaklık nem sensörü
    [92]  FT-004-B Sıcaklık Sensörü
    [93]  Ford Araba Anahtarı
    [94]  Philips dış mekan sıcaklık sensörü (tür AJ3650)
    [95]  Schrader TPMS EG53MA4, Saab, Opel, Vauxhall, Chevrolet
    [96]  Nexa
    [97]  ThermoPro TP08/TP12/TP20 termometre
    [98]  GE Color Effects
    [99]  X10 Güvenlik
    [100]  Interlogix GE UTC Güvenlik Cihazları
    [101]* Dish uzaktan kumanda 6.3
    [102]  SimpliSafe Ev Güvenlik Sistemi (Tuş Takımı kodları için otomatik kazanç devre dışı bırakma gerektirebilir)
    [103]  Sensible Living Mini-Bitki Nem Sensörü
    [104]  Kablosuz M-Bus, Mod C&T, 100kbps (-f 868.95M -s 1200k)
    [105]  Kablosuz M-Bus, Mod S, 32.768kbps (-f 868.3M -s 1000k)
    [106]* Kablosuz M-Bus, Mod R, 4.8kbps (-f 868.33M)
    [107]* Kablosuz M-Bus, Mod F, 2.4kbps
    [108]  Hyundai WS SENZOR Uzaktan Sıcaklık Sensörü
    [109]  WT0124 Havuz Termometresi
    [110]  PMV-107J (Toyota) TPMS
    [111]  Emos TTX201 Sıcaklık Sensörü
    [112]  Ambient Weather TX-8300 Sıcaklık/Nem Sensörü
    [113]  Ambient Weather WH31E Termo-Nem Sensörü, EcoWitt WH40 yağmur ölçeri, WS68 hava istasyonu
    [114]  Maverick ET73
    [115]  Honeywell ActivLink, Kablosuz Zil
    [116]  Honeywell ActivLink, Kablosuz Zil (FSK)
    [117]* ESA1000 / ESA2000 Enerji Monitörü
    [118]* Biltema yağmur ölçeri
    [119]  Bresser Hava Durumu Merkezi 5-in-1
    [120]  Digitech XC-0324 / AmbientWeather FT005TH sıcaklık/nem sensörü
    [121]  Opus/Imagintronix XT300 Toprak Nemi
    [122]  FS20 / FHT
    [123]* Jansite TPMS Model TY02S
    [124]  LaCrosse/ELV/Conrad WS7000/WS2500 hava durumu sensörleri
    [125]  TS-FT002 Kablosuz Ultrasonik Tank Sıvı Seviye Ölçeri Sıcaklık Sensörü ile
    [126]  Companion WTR001 Sıcaklık Sensörü
    [127]  Ecowitt Kablosuz Dış Mekan Termometresi WH53/WH0280/WH0281A
    [128]  DirecTV RC66RX Uzaktan Kumanda
    [129]* Eurochron sıcaklık ve nem sensörü
    [130]  IKEA Sparsnas Enerji Sayacı Monitörü
    [131]  Microchip HCS200/HCS300 KeeLoq Hopping Kodlayıcı tabanlı uzaktan kumandalar
    [132]  TFA Dostmann 30.3196 T/H dış mekan sensörü
    [133]  Rubicson 48659 Termometre
    [134]  AOK Hava Durumu İstasyonu Holman Industries iWeather WS5029, Conrad AOK-5056, Optex 990018 yeniden markalaması
    [135]  Philips dış mekan sıcaklık sensörü (tür AJ7010)
    [136]  ESIC EMT7110 güç sayacı
    [137]  Globaltronics QUIGG GT-TMBBQ-05
    [138]  Globaltronics GT-WT-03 Sensör
    [139]  Norgo NGE101
    [140]  Elantra2012 TPMS
    [141]  Auriol HG02832, HG05124A-DCF, Rubicson 48957 sıcaklık/nem sensörü
    [142]  Fine Offset Electronics/ECOWITT WH51, SwitchDoc Labs SM23 Toprak Nem Sensörü
    [143]  Holman Industries iWeather WS5029 hava durumu istasyonu (eski PWM)
    [144]  TBH hava sensörü
    [145]  WS2032 hava durumu istasyonu
    [146]  Auriol AFW2A1 sıcaklık/nem sensörü
    [147]  TFA Drop Yağmur Ölçeri 30.3233.01
    [148]  DSC Güvenlik İletişimi (WS4945)
    [149]  ERT Standart Tüketim Mesajı (SCM)
    [150]* Klimalogg
    [151]  Visonic powercode
    [152]  Eurochron EFTH-800 sıcaklık ve nem sensörü
    [153]  Cotech 36-7959, SwitchDocLabs FT020T USB'li kablosuz hava durumu istasyonu
    [154]  Standart Tüketim Mesajı Artı (SCMplus)
    [155]  Fine Offset Electronics WH1080/WH3080 Hava Durumu İstasyonu (FSK)
    [156]  Abarth 124 Spider TPMS
    [157]  Missil ML0757 hava durumu istasyonu
    [158]  Sharp SPC775 hava durumu istasyonu
    [159]  Insteon
    [160]  ERT Aralık Veri Mesajı (IDM)
    [161]  ERT Aralık Veri Mesajı (IDM) Ağ Sayacı için
    [162]* ThermoPro-TX2 sıcaklık sensörü
    [163]  Acurite 590TX Sıcaklık opsiyonel Nem ile
    [164]  Security+ 2.0 (Anahtarlık)
    [165]  TFA Dostmann 30.3221.02 T/H Dış Mekan Sensörü (ayrıca 30.3249.02)
    [166]  LaCrosse Technology View LTV-WSDTH01 Breeze Pro Rüzgar Sensörü
    [167]  Somfy RTS
    [168]  Schrader TPMS SMD3MA4 (Subaru) 3039 (Infiniti, Nissan, Renault)
    [169]* Nice Flor-s kapılar için uzaktan kumanda
    [170]  LaCrosse Technology View LTV-WR1 Çoklu Sensör
    [171]  LaCrosse Technology View LTV-TH Termo/Nem Sensörü
    [172]  Bresser Hava Durumu Merkezi 6-in-1, 7-in-1 iç mekan, toprak, yeni 5-in-1, 3-in-1 rüzgar ölçeri, Froggit WH6000, Ventus C8488A
    [173]  Bresser Hava Durumu Merkezi 7-in-1, Hava Kalitesi PM2.5/PM10 7009970, CO2 7009977, HCHO/VOC 7009978 sensörleri
    [174]  EcoDHOME Akıllı Soket ve MCEE Güneş monitörü
    [175]  LaCrosse Technology View LTV-R1, LTV-R3 Yağmur Ölçeri, LTV-W1/W2 Rüzgar Sensörü
    [176]  BlueLine Innovations Güç Maliyet Monitörü
    [177]  Burnhard BBQ termometresi
    [178]  Security+ (Anahtarlık)
    [179]  Cavius duman, ısı ve su dedektörü
    [180]  Jansite TPMS Model Solar
    [181]  Amazon Basics Et Termometresi
    [182]  TFA Marbella Havuz Termometresi
    [183]  Auriol AHFL sıcaklık/nem sensörü
    [184]  Auriol AFT 77 B2 sıcaklık sensörü
    [185]  Honeywell CM921 Kablosuz Programlanabilir Oda Termostatı
    [186]  Hyundai TPMS (VDO)
    [187]  RojaFlex panjur ve uzaktan cihazlar
    [188]  Marlec Solar iBoost+ sensörleri
    [189]  Somfy io-homecontrol
    [190]  Ambient Weather WH31L (FineOffset WH57) Yıldırım-Çarpması sensörü
    [191]  Markisol, E-Motion, BOFU, Rollerhouse, BF-30x, BF-415 perde uzaktan kumandası
    [192]  Govee Su Sızıntısı Dedektörü H5054, Kapı İletişim Sensörü B5023
    [193]  Clipsal CMR113 Cent-a-meter güç sayacı
    [194]  Inkbird ITH-20R sıcaklık nem sensörü
    [195]  RainPoint toprak sıcaklığı ve nem sensörü
    [196]  Atech-WS308 sıcaklık sensörü
    [197]  Acurite Izgara/Et Termometresi 01185M
    [198]* EnOcean ERP1
    [199]  Linear Megacode Garaj/Kapı Uzaktan Kumandaları
    [200]* Auriol 4-LD5661/4-LD5972/4-LD6313 sıcaklık/yağmur sensörleri
    [201]  Kamyonlar için Markasız SolarTPMS
    [202]  Funkbus / Instafunk (Berker, Gira, Jung)
    [203]  Porsche Boxster/Cayman TPMS
    [204]  Jasco/GE Choice Alert Güvenlik Cihazları
    [205]  Telldus hava durumu istasyonu FT0385R sensörleri
    [206]  LaCrosse TX34-IT yağmur ölçeri
    [207]  SmartFire Proflame 2 uzaktan kumanda
    [208]  AVE TPMS
    [209]  SimpliSafe Gen 3 Ev Güvenlik Sistemi
    [210]  Yale HSA (Ev Güvenlik Alarmı), YES-Alarmkit
    [211]  Regency Tavan Vantilatörü Uzaktan Kumandası (-f 303.75M to 303.96M)
    [212]  Renault 0435R TPMS
    [213]  Fine Offset Electronics WS80 hava durumu istasyonu
    [214]  EMOS E6016 DCF77'li hava durumu istasyonu
    [215]  Emax W6, Altronics x7063/4, Optex 990040/50/51, Orium 13093/13123, Infactory FWS-1200, Newentor Q9, Otio 810025, Protmex PT3390A, Jula Marquant 014331/32, TechniSat IMETEO X6 76-4924-00, Hava Durumu İstasyonu veya sıcaklık/nem sensörü yeniden markalaması
    [216]* ANT ve ANT+ cihazları
    [217]  EMOS E6016 yağmur ölçeri
    [218]  Microchip HCS200/HCS300 KeeLoq Hopping Kodlayıcı tabanlı uzaktan kumandalar (FSK)
    [219]  Fine Offset Electronics WH45 hava kalitesi sensörü
    [220]  Maverick XR-30 BBQ Sensörü
    [221]  Fine Offset Electronics WN34S/L/D ve Froggit DP150/D35 sıcaklık sensörü
    [222]  Rubicson Havuz Termometresi 48942
    [223]  Badger ORION su sayacı, 100kbps (-f 916.45M -s 1200k)
    [224]  GEO minim+ enerji monitörü
    [225]  TyreGuard 400 TPMS
    [226]  Kia TPMS (-s 1000k)
    [227]  SRSmith Havuz Işığı Uzaktan Kumandası SRS-2C-TX (-f 915M)
    [228]  Neptune R900 akış sayaçları
    [229]  WEC-2103 sıcaklık/nem sensörü
    [230]  Vauno EN8822C
    [231]  Govee Su Sızıntısı Dedektörü H5054
    [232]  TFA Dostmann 14.1504.V2 Radyo kontrollü ızgara ve et termometresi
    [233]* CED7000 Atış Zamanlayıcısı
    [234]  Watchman Sonic Gelişmiş / Artı, Tekelek
    [235]  Yağ Ultrasonik SMART FSK
    [236]  Gasmate BA1008 et termometresi
    [237]  Flowis akış sayaçları
    [238]  Kablosuz M-Bus, Mod T, 32.768kbps (-f 868.3M -s 1000k)
    [239]  Revolt NC-5642 Enerji Sayacı
    [240]  LaCrosse TX31U-IT, The Weather Channel WS-1910TWC-IT
    [241]  EezTire E618, Carchet TPMS, TST-507 TPMS
    [242]* Baldr / RainPoint yağmur ölçeri.
    [243]  Celsia CZC1 Termostat
    [244]  Fine Offset Electronics WS90 hava durumu istasyonu
    [245]* ThermoPro TX-2C Termometre ve Nem sensörü
    [246]  TFA 30.3151 Hava Durumu İstasyonu
    [247]  Bresser su sızıntısı
    [248]* Nissan TPMS
    [249]  Bresser yıldırım
    [250]  Schou 72543 Gün Yağmur Ölçeri, Motonet MTX Yağmur, MarQuant Yağmur Ölçeri, TFA Dostmann 30.3252.01/47.3006.01 Yağmur Ölçeri ve Termometre, ADE WS1907
    [251]  Fine Offset / Ecowitt WH55 su sızıntısı sensörü
    [252]  BMW Gen4-Gen5 TPMS ve Audi TPMS Basınç Uyarısı, çok markalı HUF/Beru, Continental, Schrader/Sensata, Audi
    [253]  Watts WFHT-RF Termostat
    [254]  Thermor DG950 hava durumu istasyonu
    [255]  Mueller Hot Rod su sayacı
    [256]  ThermoPro TP28b Çok Uzun Menzilli Kablosuz Et Termometresi Smoker BBQ Izgara için
    [257]  BMW Gen2 ve Gen3 TPMS
    [258]  Chamberlain CWPIRC PIR Sensörü
    [259]  ThermoPro Et Termometreleri, TP829B 4 prob sadece sıcaklık ile
    [260]* Arad/Master Sayacı Dialog3G su yardımcı programı sayacı
    [261]  Geevon TX16-3 dış mekan sensörü
    [262]  Fine Offset Electronics WH46 hava kalitesi sensörü
    [263]  Vevor Kablosuz Hava Durumu İstasyonu 7-in-1
    [264]  Arexx Multilogger IP-HA90, IP-TH78EXT, TSN-70E
    [265]  Rosstech Dijital Kontrol Ünitesi DCU-706/Sundance/Jacuzzi
    [266]  Risco 2 Yönlü Agility protokolü, Risco PIR/PET Sensörü RWX95P
    [267]  ThermoPro Et Termometreleri, TP828B 2 prob Sıcaklık, BBQ Hedef DÜŞÜK ve YÜKSEK ile
    [268]  Bresser Thermo-/Hygro-Sensor Explore Scientific ST1005H
    [269]  DeltaDore X3D cihazları
    [270]* Quinetic
    [271]  Landis & Gyr Gridstream Güç Sayacı 9.6k
    [272]  Landis & Gyr Gridstream Güç Sayacı 19.2k
    [273]  Landis & Gyr Gridstream Güç Sayacı 38.4k
    [274]  Revolt ZX-7717 güç sayacı
    [275]  GM-Aftermarket TPMS
    [276]  RainPoint HCS012ARF Yağmur Ölçeri sensörü
    [277]  Apator Metra E-RM 30
    [278]  ThermoPro TX-7B Dış Mekan Termometre Nem Ölçer
    [279]  Nexus, CRX, Prego saunası sıcaklık sensörü
    [280]  Homelead HG9901 (Geevon, Dr.Meter, Royal Gardineer) toprak nemi/sıcaklık/ışık seviyesi sensörü
    [281]  Maverick XR-50 BBQ Sensörü
    [282]  Badger Meter'den Orion Endpoint, GIF2014W-OSE, su sayacı, 904.4 Mhz'den 924.6Mhz'ye atlama (-s 1600k)
    [283]  Fine Offset Electronics WH43 hava kalitesi sensörü
    [284]  Baldr E0666TH Termo-Nem Ölçer
    [285]  bm5-v2 12V Pil Monitörü
    [286]  Evrensel (Tersine çevrilebilir) 24V Fan Kontrolcü
    [287]  Fine Offset Electronics WS85 hava durumu istasyonu
    [288]  Oria WA150KM dondurucu ve buzdolabı termometresi
    [289]  Voltcraft EnergyCount 3000 (ec3k)
    [290]  Badger Meter'den Orion Endpoint, GIF2020OCECNA, su sayacı, 904.4 Mhz'den 924.6Mhz'ye atlama (-s 1600k)
    [291]  Geevon TX19-1 dış mekan sensörü

* Varsayılan olarak devre dışı, etkinleştirmek için -R n veya bir yapılandırma dosyası kullanın



		= Giriş cihazı seçimi =
	RTL-SDR cihaz sürücüsü mevcut.
  [-d <RTL-SDR USB cihaz indeksi>] (varsayılan: 0)
  [-d :<RTL-SDR USB cihaz seri numarası (rtl_eeprom -s ile ayarlanabilir)>]
	RTL-SDR için kazanç ayarlamak için -g <gain> kullanarak genel bir kazanç ayarlayın (dB cinsinden).
	SoapySDR cihaz sürücüsü mevcut.
  [-d ""] Varsayılan SoapySDR cihazını aç
  [-d driver=rtlsdr] Örn. belirli SoapySDR cihazını aç
	SoapySDR için kazanç ayarlamak için -g ELEM=değer,ELEM=değer,... kullanın örn. -g LNA=20,TIA=8,PGA=2 (LimeSDR için).
  [-d rtl_tcp[:[//]host[:port]] (varsayılan: localhost:1234)
	Bağlanmak için ana bilgisayar/bağlantı noktasını belirtin örn. -d rtl_tcp:127.0.0.1:1234



		= Gain seçeneği =
  [-g <gain>] (varsayılan: auto)
	RTL-SDR için: dB cinsinden gain ("0" otomatiktir).
	SoapySDR için: otomatik dağıtım için dB cinsinden gain ("" otomatiktir) veya gain elemanları dizisi.
	Örn. LimeSDR için "LNA=20,TIA=8,PGA=2".



		= Flex kod çözücü spec =
Esnek genel amaçlı bir kod çözücü eklemek için -X <spec> kullanın.

<spec> "key=value[,key=value...]"
Ortak anahtarlar:
	name=<name> (veya: n=<name>)
	modulation=<modulation> (veya: m=<modulation>)
	short=<short> (veya: s=<short>)
	long=<long> (veya: l=<long>)
	sync=<sync> (veya: y=<sync>)
	reset=<reset> (veya: r=<reset>)
	gap=<gap> (veya: g=<gap>)
	tolerance=<tolerance> (veya: t=<tolerance>)
	priority=<n> : kod çözücüyü sadece yedek olarak çalıştır
nerede:
<name> çıktıda ihtiyacınız olan herhangi bir açıklayıcı ad etiketi olabilir
<modulation> şunlardan biridir:
	OOK_MC_ZEROBIT :  Sabit lider sıfır bit ile Manchester Kodu
	OOK_PCM :         Non Return to Zero kodlama (Pulse Code)
	OOK_RZ :          Return to Zero kodlama (Pulse Code)
	OOK_PPM :         Pulse Position Modulation
	OOK_PWM :         Pulse Width Modulation
	OOK_DMC :         Differential Manchester Code
	OOK_PIWM_RAW :    Raw Pulse Interval and Width Modulation
	OOK_PIWM_DC :     Differential Pulse Interval and Width Modulation
	OOK_MC_OSV1 :     OSv1 cihazları için Manchester Kodu
	FSK_PCM :         FSK Pulse Code Modulation
	FSK_PWM :         FSK Pulse Width Modulation
	FSK_MC_ZEROBIT :  Sabit lider sıfır bit ile Manchester Kodu
<short>, <long>, <sync> nominal modülasyon zamanlamaları (us cinsinden),
<reset>, <gap>, <tolerance> maksimum modülasyon zamanlamaları (us cinsinden):
PCM/RZ  short: Darbenin nominal genişliği [us]
         long: Bit periyodunun nominal genişliği [us]
PPM     short: '0' aralığının nominal genişliği [us]
         long: '1' aralığının nominal genişliği [us]
PWM     short: '1' darbesinin nominal genişliği [us]
         long: '0' darbesinin nominal genişliği [us]
         sync: senkronizasyon darbesinin nominal genişliği [us] (opsiyonel)
ortak    gap: Yeni bit satırından önce maksimum aralık boyutu [us]
        reset: Mesaj Sonundan önce maksimum aralık boyutu [us]
    tolerance: Maksimum darbe sapması [us] (opsiyonel).
Kullanılabilir seçenekler:
	bits=<n> : sadece en az bir satır <n> bit ise eşleştir
	rows=<n> : sadece <n> satır varsa eşleştir
	repeats=<n> : sadece bazı satırlar <n> kez tekrarlanırsa eşleştir
		opt>=n en az <n> ve opt<=n en çok <n> eşleştirmek için kullanın
	invert : tüm bitleri ters çevir
	reflect : her baytı yansıt (MSB ilkten MSB sonuna)
	decode_uart : UART 8n1 (10'dan 8'e) kod çözme
	decode_dm : Differential Manchester kod çözme
	decode_mc : Manchester kod çözme
	match=<bits> : sadece <bitler> bulunursa eşleştir
	preamble=<bits> : <bitler> öncülü ile eşleştir ve hizala
		<bitler> {<bit sayısı>}<onaltılık sayı olarak bitler> bir satır spec'idir
	unique : yinelenen satır çıktısını bastır

	countonly : detaylı satır çıktısını bastır

Örn. -X "n=doorbell,m=OOK_PWM,s=400,l=800,r=7000,g=1000,match={24}0xa9878c,repeats>=3"



		= Çıktı formatı seçeneği =
  [-F log|kv|json|csv|mqtt|influx|syslog|trigger|rtl_tcp|http|null] Kodu çözülmüş çıktıyı verilen formatta üret.
	Bu seçenek olmadan varsayılan LOG ve KV çıktısıdır. Varsayılanı kaldırmak için "-F null" kullanın.
	Çıktıyı dosyaya eklemek için :<dosya adı> (örn. -F csv:log.csv), varsayılan stdout.
  [-F mqtt[s][:[//]host[:port][,<seçenekler>]] (varsayılan: localhost:1883)
	MQTT sunucusunu örn. -F mqtt://localhost:1883 ile belirtin
	Varsayılan kullanıcı adı ve parola MQTT_USERNAME ve MQTT_PASSWORD ortam değişkenlerinden okunur.
	MQTT seçeneklerini örn. -F "mqtt://host:1883,opt=arg" ile ekleyin
	MQTT seçenekleri: user=foo, pass=bar, retain[=0|1], <format>[=topic]
	Desteklenen MQTT formatları: (varsayılan hepsi)
	  availability: kullanılabilirlik gönderir (çevrimiçi/çevrimdışı)
	  events: JSON olay verileri gönderir, varsayılan "<base>/events"
	  states: JSON durum verileri gönderir, varsayılan "<base>/states"
	  devices: iç içe konularda cihaz ve sensör bilgileri gönderir,
	           varsayılan "<base>/devices[/type][/model][/subtype][/channel][/id]"
	Bir temel konu base=<konu> ile ayarlanabilir, varsayılan "rtl_433/HOSTNAME".
	Herhangi bir konu dizesi temel konuyu geçersiz kılar ve [/model] gibi anahtarları genişletir
	Örn. -F "mqtt://localhost:1883,user=KULLANICIADI,pass=PAROLA,retain=0,devices=rtl_433[/id]"
	TLS için örn. -F "mqtts://host,tls_cert=<yol>,tls_key=<yol>,tls_ca_cert=<yol>" kullanın
	MQTT ile her rtl_433 örneği farklı bir sürücü seçimi gerektirir. MQTT Client-ID sürücü dizesinden hesaplanır.
	Birden fazla RTL-SDR kullanıyorsanız, belki bir seri numarası ayarlayın ve bununla seçin (yanlış anteni almamaya yardımcı olur).
  [-F influx[:[//]host[:port][/<path and options>]]
	InfluxDB 2.0 sunucusunu örn. -F "influx://localhost:9999/api/v2/write?org=<org>&bucket=<bucket>,token=<authtoken>" ile belirtin
	InfluxDB 1.x sunucusunu örn. -F "influx://localhost:8086/write?db=<db>&p=<password>&u=<user>" ile belirtin
	  InfluxDB'de doğru zaman damgaları için ek parametre -M time:unix:usec:utc önerilir
  [-F syslog[:[//]host[:port] (varsayılan: localhost:514)
	Syslog için ana bilgisayar/bağlantı noktasını örn. -F syslog:127.0.0.1:1514 ile belirtin
  [-F trigger:/yol/dosya]
	Her olay için yola "1" yazan bir çıktı ekleyin, örn. bir GPIO ile kullanın
  [-F rtl_tcp[:[//]bind[:port]] (varsayılan: localhost:1234)
	Bir rtl_tcp geçiş sunucusu ekleyin
  [-F http[:[//]bind[:port]] (varsayılan: 0.0.0.0:8433)
	Bir HTTP API sunucusu ekleyin, bir arayüz örn. http://localhost:8433/ adresindedir



		= Meta bilgi seçeneği =
  [-M time[:<seçenekler>]|protocol|level|noise[:<sn>]|stats|bits] Her çıktı satırına çeşitli meta veriler ekleyin.
	Geçerli tarih ve saat meta verilerini eklemek için "time" kullanın (canlı girişler için ön ayar).
	Örnek konumu meta verilerini eklemek için "time:rel" kullanın (dosya okuma ve stdin için ön ayar).
	Zaman meta verisi olarak unix epokundan beri geçen saniyeleri göstermek için "time:unix" kullanın. Bu her zaman UTC'dir.
	Zamanı ISO-8601 formatında (YYYY-MM-DD"T"hh:mm:ss) göstermek için "time:iso" kullanın.
	Zaman meta verisini kaldırmak için "time:off" kullanın.
	Tarih saat meta verilerine mikrosaniyeler eklemek için "time:usec" kullanın.
	Saat dilimi ofseti ile zamanı çıkarmak için "time:tz" kullanın.
	Zamanı UTC'de çıkarmak için "time:utc" kullanın.
		(bu ayrıca TZ ortam değişkeni ayarlanarak çağrılarak da gerçekleştirilebilir).
		"usec" ve "utc" diğer seçeneklerle birleştirilebilir, örn. "time:iso:utc" veya "time:unix:usec".
	Dosya girişlerini (N-kez) gerçek zamanında yeniden oynatmak için "replay[:N]" kullanın.
	Kod çözücü protokol numarası meta verisini çıkarmak için "protocol" / "noprotocol" kullanın.
	Modülasyon, Frekans, RSSI, SNR ve Gürültü meta verilerini eklemek için "level" kullanın.
Aralıklarla tahmini gürültü seviyesini raporlamak için "noise[:<sn>]" kullanın (varsayılan: 10 saniye).
	İstatistikleri raporlamak için "stats[:[<seviye>][:<aralık>]]" kullanın (varsayılan: 600 saniye).
	  seviye 0: rapor yok, 1: başarılı cihazları raporla, 2: aktif cihazları raporla, 3: tümünü raporla
	Kod çıktılarına bit temsilini eklemek için "bits" kullanın (hata ayıklama için).



		= Dosya okuma seçeneği =
  [-r <dosya adı>] Verileri bir alıcı yerine giriş dosyasından oku
	Parametreler tam yoldan, dosya adından ve uzantıdan algılanır.

	Bir merkez frekans 'M', 'Hz', 'kHz', 'MHz' veya 'GHz' sonekli (kesirli) sayı olarak algılanır.

	Bir örnekleme hızı 'k', 'sps', 'ksps', 'Msps' veya 'Gsps' sonekli (kesirli) sayı olarak algılanır.

	Dosya içeriği ve formatı parametre olarak algılanır, olası seçenekler:
	'cu8', 'cs16', 'cf32' ('IQ' varsayılan), ve 'am.s16'.

	Parametreler alfasayısal olmayan karakterlerle ayrılmalıdır ve büyük/küçük harf duyarsızdır.
	Geçersiz kılmalar kolon (':') ile ayrılarak önek olarak eklenebilir

	Örn. uzantıya göre varsayılan algılama: path/filename.am.s16
	zorla geçersiz kırmalar: am:s16:path/filename.ext

	Boru hatlarından okumak da format seçeneklerini destekler.
	Örn. karmaşık 32-bit float okuma: CU32:-



		= Dosya yazma seçeneği =
  [-w <dosya adı>] Veri akışını çıktı dosyasına kaydet ('-' örnekleri stdout'a döker)
  [-W <dosya adı>] Veri akışını çıktı dosyasına kaydet, mevcut dosyanın üzerine yaz
	Parametreler tam yoldan, dosya adından ve uzantıdan algılanır.

	Dosya içeriği ve formatı parametre olarak algılanır, olası seçenekler:
	'cu8', 'cs8', 'cs16', 'cf32' ('IQ' varsayılan),
	'am.s16', 'am.f32', 'fm.s16', 'fm.f32',
	'i.f32', 'q.f32', 'logic.u8', 'ook', ve 'vcd'.

	Parametreler alfasayısal olmayan karakterlerle ayrılmalıdır ve büyük/küçük harf duyarsızdır.
	Geçersiz kılmalar kolon (':') ile ayrılarak önek olarak eklenebilir

	Örn. uzantıya göre varsayılan algılama: path/filename.am.s16
	zorla geçersiz kırmalar: am:s16:path/filename.ext

```


Bazı örnekler:

| Komut | Açıklama
|---------|------------
| `rtl_433` | Varsayılan alma modu, bulunan ilk cihazı kullan, 433.92 MHz'de 250k örnekleme hızıyla dinle.
| `rtl_433 -C si` | Varsayılan alma modu, ayrıca birimleri metrik sistemine dönüştür.
| `rtl_433 -f 868M -s 1024k` | 868 MHz ve 1024k örnekleme hızıyla dinle.
| `rtl_433 -M hires -M level` | Mikrosaniye hassasiyetinde zaman damgaları ve alma seviyeleri (kazanca bağlı) raporla.
| `rtl_433 -R 1 -R 8 -R 43` | İstenen cihazlar için sadece belirli kod çözücüleri etkinleştir.
| `rtl_433 -A` | Darbe analizörünü etkinleştir. Darbe, boşluk ve periyot zamanlamalarını özetler. Kod çözücüleri devre dışı bırakmak için `-R 0` ile kullanılabilir.
| `rtl_433 -S all -T 120` | Tüm algılanan sinyalleri kaydet (`g###_###M_###k.cu8`). 2 dakika çalıştır.
| `rtl_433 -K FILE -r dosya_adı` | Canlı veri almak yerine kaydedilmiş bir veri dosyasını oku. Çıktıyı dosya adlarıyla etiketle.
| `rtl_433 -F json -M utc \| mosquitto_pub -t home/rtl_433 -l` | Çıktıyı JSON formatında MQTT mesajları olarak ağa aktaracaktır. Bir test MQTT istemcisi `examples/mqtt_rtl_433_test_client.py` dosyasında bulunabilir.
| `rtl_433 -f 433.53M -f 434.02M -H 15` | 15 saniyelik atlama aralığıyla iki frekansı yoklar.

## Güvenlik

Lütfen dikkat: `rtl_433`'ü kullanımı güvenli hale getirmeyi amaçlıyoruz, ancak güvenli olduğu varsayılmamalıdır.
Örneğin `sudo` ile çalıştırmak için hiçbir neden yok, dosyaları hiçbir kontrol olmadan okuyoruz ve yazıyoruz.

Çıktı kelimenin tam anlamıyla havadan çekilir, güvenilir değildir.
Aşağı akış sistemlerini verilerle besliyorsanız, kenar durumlarının kontrol edildiğinden ve işlendiğinden emin olun.
Ağ girişleri ve çıktıları güvenilen bir yerel ağda kullanım içindir, filtrelenmemiş veri içerecektir ve alıcıyı aşırı yükleyebilir
(örneğin MQTT çıktısının bir radyo vericisi olan herkes tarafından kontrol edilebileceğini bilin).

## Google Grubu

rtl_433 hakkında daha fazla bilgi için Google grubuna katılın:
https://groups.google.com/forum/#!forum/rtl_433


## Sorun Giderme

Bu hatayı görüyorsanız:

    Kernel driver is active, or device is claimed by second instance of librtlsdr.
    In the first case, please either detach or blacklist the kernel module
    (dvb_usb_rtl28xxu), or enable automatic detaching at compile time.

ardından

    sudo rmmod rtl2832_sdr dvb_usb_rtl28xxu rtl2832

veya ekleyin

    blacklist dvb_usb_rtl28xxu

/etc/modprobe.d/blacklist.conf dosyasına

## Sürümler

Kullanılan sürüm numaralandırma şeması yıl.aydır. Sürümler arası API uyumlu olmaya çalışıyoruz ancak odak noktamız bakım kolaylığıdır.

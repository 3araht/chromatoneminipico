![chromatoneminipico](https://github.com/3araht/chromatoneminipico/blob/main/pictures/chromatoneminipico_toppage.jpg)

# chromatoneminipico キーボード
chromatonemini （クロマトーンミニ）キーボードは3オクターブ分（37音）を網羅したシンプルデザインのクロマトーン MIDI キーボードです。
chromatonemini は、クロマトーン発明者の[大川 ワタルさん](https://muto-method.com/profile.html)から受託して作成致しました。
大川さんに自作キーボードキットとしての販売許可をいただきました♪ ロゴも chromatonemini のために提供してくださいました。  
chromatoneminipico は chromatonemini の Raspberry Pi Pico 版です。  
Raspberry Pi Pico は Pro Micro よりも IO の数が多いため、音階キー111鍵盤 全てが独立して識別できるようになっています。
これにより、 QWERTY 配列や、クロマチック・ボタン・アコーディオン の C-System、B-System の配列にも切り替えることができるようになりました！！！

カラーリングは [Wholetone Revolution](https://chromatone.jp/chromatone/index.html) をオマージュして赤色になっています（色味は全然ちがいますが。。。）。  

幅は約42cm。ちょうどA3用紙に長手方向の長さくらいです。  
37鍵あるピアノ鍵盤MIDIキーボードより省スペースでDTMに最適？かも知れません。

chromatoneminipico は PC / Mac / iPad / iPhone / Android などで動作します(ただし、Raspberry Pi Pico にファームウェアを書き込むときに PC / Mac が必要)。

コネクタが Lightning タイプの iPad や iPhone で使う場合、下記に示すアダプターを使って電源供給しながら使えることを確認しています。
iPad や iPhone で chromatoneminipico を使う場合には電源が必要ですので、必ず "[Lightning - USB 3カメラアダプタ](https://www.apple.com/jp/shop/product/MK0W2AM/A/)" をお使いください。
"Lightning - USBカメラアダプタ" では電源供給ができません。

なお、USB-C タイプの iPad Air 4th Gen で試したところ、電源供給なしに問題なく動作させることができました。

ロータリーエンコーダは長押しでモード切り替えレイヤーへ。短押しでミュート切り替え、回転させるとシステム音量の調整に使用することが可能です。

オプションにより、LED を搭載すれば写真のようにバックライト点灯させることが可能です（LEDのハンダ付けは難易度が高いので、ご注意ください）。

# 外観および使用例
姉妹品の [chromatonemini](https://github.com/3araht/chromatonemini) の使用例はこちら。  
Chromatic Music Lab. の [CHROMATONE-MINI【DEMO】](https://youtu.be/WQA9r8nkZjo) をご覧ください!  
また、こちらに[機能詳細紹介動画](https://youtu.be/7tFm5GolF3g)がございます。

# キーボードキット
chromatoneminipico キーボードキットは BOOTH でお求めいただけます。  
[BOOTH 販売ページへのリンクはこちら](https://3araht.booth.pm/)。
BOOTH では、chroamtonemini / chromatoneminipico の他、クロマチックボタンアコーディオンを模した MIDIキーボードの giabalanai、 giabaLEnai、 giabaRInai、 giabaRInaix2 がお求めいただけます。

遊舎工房でもお求めいただけるようになりました！！！  
[遊舎工房 販売ページへのリンクはこちら](https://shop.yushakobo.jp/collections/keyboard/products/3069)。

# ファームウェア

chromatoneminipico は QMK firmware を使っています。  
ただし 2021/11/13 現在 正式に Raspberry Pi に対応していません。  
[せきごん さんの開拓された手法](https://scrapbox.io/self-made-kbds-ja/RP2040対応のQMK(非公式)を動かす) を使わせていただいております。  

chromatoneminipico のソースは[こちら](https://github.com/3araht/chromatoneminipico/blob/main/temp/qmk_firmware/keyboards/chromatoneminipico) からダウンロード下さい。

もしくは、こちらのコンパイル済の [uf2 file](https://github.com/3araht/chromatoneminipico/blob/main/chromatoneminipico_led.uf2) をお使いください.

# ビルドガイド

[日本語ビルドガイド](https://github.com/3araht/chromatoneminipico/blob/main/docs/build.md)

# コンタクト先:
Twitter と YouTube はじめました。  
http://twitter.com/3araht  
https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/  
https://www.instagram.com/3araht/  


# chromatoneminipico keyboard
chromatonemini keyboard is a simple-design Chromatone mini MIDI keyboard that covers 3 octaves (37 notes).
chromatonemini was created on behalf of [Mr. Wataru Ohkawa](https://muto-method.com/en/profile.html), the inventor of chromatone. Mr. Ohkawa gave me permission to sell it as a keyboard kit ♪ He also provided his logo for chromatonemini.  
chromatoneminipico is a Raspberry Pi Pico edition of chromatonemini. QWERTY layout, C-System and B-System of chromatic button accordion layouts are now available.  

chromatoneminipico works with PC, Mac, iPad, iPhone, and Android(However, either PC or Mac is needed for flashing firmware to Raspberry Pi Pico).

This work pays homage to [Wholetone Revolution](https://muto-method.com/en/history.html), and the red color is coming from it (The color tone is quite different, though...).  

The width is approx. 42 cm (= 16.5"), as wide as the height of A3 paper size.
Since the 37-key chromatoneminipico keyboard is smaller than piano type 37-key keyboards, it requires less desk space and might be beneficial for DTM purposes.

When using it with an iPad or iPhone, it works when the below adapter is used with a power supply. The power supply is necessary to use chromatoneminipico on iPad and iPhone. Make sure to use "[Lightning to USB 3 Camera Adapter](https://www.apple.com/shop/product/MK0W2AM/A/)", not "Lightning to USB Camera Adapter."  

Confirmed with an iPad Air 4th Gen, which has a USB-C port, it worked without the power supply.

A rotary encoder can be used to change the settings of chromatoneminipico by long-pressing the push-button of the encoder, mute/unmute by clicking, and adjusting the system volume of your computer by rotating the encoder.

# How it looks & how it works
Check this out!  
Chromatic Music Lab. [CHROMATONE-MINI【DEMO】](https://youtu.be/WQA9r8nkZjo)  
A detailed introduction is shown [here](https://youtu.be/7tFm5GolF3g).
Those are actually [chromatonemini](https://github.com/3araht/chromatonemini) and not chromatoneminipico, but you'll get the picture.

# Keyboard kit
The keyboard kit is available from [BOOTH](https://3araht.booth.pm/).  

Click [here](https://www.tenso.com/en/static/lp_shop_booth) for BOOTH overseas shipping!

Now it's available at Yushakobo as well!!!  
Click [here](https://shop.yushakobo.jp/collections/keyboard/products/3069) for Yushakobo's chromatoneminipico page.

# Firmware

chromatoneminipico uses QMK for its firmware. However, as of Nov 13th, 2021, QMK does not fully support Raspberry Pi...  
Thanks to sekigon-gonnoc, [the method sekigon-gonnoc has built](https://scrapbox.io/self-made-kbds-ja/RP2040対応のQMK(非公式)を動かす) is used.  

Please download chromatoneminipico codes from [here](https://github.com/3araht/chromatoneminipico/blob/main/temp/qmk_firmware/keyboards/chromatoneminipico).

Or, use this pre-compiled [uf2 file](https://github.com/3araht/chromatoneminipico/blob/main/chromatoneminipico_led.uf2) for your convenience.

# Build Guide

[Build Guide in Japanese](https://github.com/3araht/chromatoneminipico/blob/main/docs/build.md)  
Try [Google Translated guide](https://translate.google.com/translate?sl=ja&tl=en&u=https://github.com/3araht/chromatoneminipico/blob/main/docs/build.md) for your language preferences. Trust me, it works quite well, more than expected.

# Contact
If you need any help, you know where to find me.  
http://twitter.com/3araht  
https://www.youtube.com/channel/UC0zYtYMoxb0P7S8DPAkl0zA/  
https://www.instagram.com/3araht/  

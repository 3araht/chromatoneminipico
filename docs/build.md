# chromatoneminipico Build Guide
**一度すべて読んでから組み立てることをお勧めします。**

chromatonemini と chromatoneminipico の違い：

- chromatonemini は ProMicro、 chromatoneminipico は Raspberry Pi Pico を使います。
- chromatoneminipico は SK6812mini-E のみ対応
- chromatoneminipico は 111鍵の全てが独立しているので、KEYMAP などで独立したキー配列に変更することができます。  
  （一番上の2列＝19鍵＋18鍵＝37鍵 はその上のグリッサンド奏法用のキーとハードウェア的につながっています。）  

## 0 ##
## パーツの確認、各部品の実装面の整理 ###
### キット付属品

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|  
|基板|1枚||
|ボトムプレート|1枚||
|M2 スペーサー |25個||
|M2 ネジ|50個||
|クッションシール|15個||
|リセットスイッチ|1個||
|タクトスイッチ|37個|主にグリッサンド奏法で用いる半音階キー用。※	華奢なので演奏は優しくお願いします。|
|TRRS コネクタ|1個|サスティンペダル接続用|
|ダイオード 1N4148|117個|音階キー用111個＋操作ボタン用4個＋ロータリーエンコーダー用1個＋サスティンペダル用1個|


### 別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|--------|  
|[Raspberry Pi Pico](https://shop.yushakobo.jp/products/raspberry-pi-pico)|1個||
|キースイッチ(CherryMX 互換品)|115個|5pin タイプ推奨。音階キー111個＋操作ボタン4個用。|
|MX対応キーキャップ|115個|1U。音階キー111個＋操作ボタン4個用。|
|[ロータリーエンコーダ(ノブ付き)](https://yushakobo.jp/shop/pec12r-4222f-s0024/)|1個|押しボタン機能付きのものを選んでください（端子が上に2本（押しボタン用）、下に3本（エンコーダー用）生えてるやつ）。長押し＋〇〇でレイヤー切り替え。|
|MicroUSBケーブル|1本|データ通信ができるケーブルである必要がありますので、充電用のケーブルは使えません。Raspberry Pi Pico を認識しない場合は、ケーブルを確認してみてください。|

### [Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|LED SK6812mini-E|116個|音階キー111個＋操作ボタン4個＋エンコーダ用1個。2の「Backlight RGB LED」を使う場合に必要。中級レベルの半田付けを伴うので、半田付け初心者の方はLEDなしで組み立てられることをお勧め致します。|
|サスティンペダル|1台|ノーマリオフタイプ。念の為、極性変換スイッチつきのものをおすすめします。|
|3.5 mm ミニジャック変換ケーブル|1本|サスティンペダルのモノラルジャックを TRRS コネクタに刺さるように変換します。|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Raspberry Pi Pico、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

オモテ面  
<img width="700" alt="PCB" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/front_pcb_rpp_r02.jpg">

裏面  

基板の裏面には、ダイオードの実装場所やキーボード名が印字されています。  
<img width="700" alt="PCB" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rear_pcb_rpp_r02.jpg">


#### 裏面には次の部品を実装します
 - ダイオード
 - リセットスイッチ
 - TRRS コネクタ
 - LED[Optional]

#### オモテ面には次の部品を実装します
 - Raspberry Pi Pico (ピンヘッダーやコンスルーを使えば裏面にも実装可能です。)
 - キースイッチ
 - タクトスイッチ
 - エンコーダ

## 1
## ダイオードの取付け ##
キーの数が多いキーボードではMatrixという手法を使ってキーが押されたかどうか判断します。
キーが必ず1個ずつしか押されないと保証されているのであれば、このダイオードは不要なのですが、
和音を弾くことがあるので複数のキーを同時に押す場面が出てきます。
このとき、Matrixという手法で複数同時押しを正しく判断するためにこのダイオードが必要になります。
詳しい説明については、[こちら](https://docs.qmk.fm/#/how_a_matrix_works)などをご覧ください。

ダイオードには向きがあります。また、図のように足を曲げておきます。
ダイオードをつまんで両端の足を同時に曲げると図の右のように比較的ちょうどいい形になります。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_bend.jpg">

キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒い線のほうが四角いフットプリント（Kと印字されている方, K はKathode（独）の頭文字らしいですが、黒（Kuro) の K で。）に合うように配置します。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_align_rpp_r02.jpg">

足を曲げて基板に這わせてダイオードを仮止めします。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_flatten.jpg">

オモテ面から見た図  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_flatten2_rpp_r02.jpg">

オモテ面から半田付けします。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_soldered_rpp_r02.jpg">

足をニッパでカットします（同上）。足は勢いよく飛んで行くので、足を押さえながら切ると良いです。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_feet_cut_rpp_r02.jpg">

これをD1 〜 D117 の117箇所半田付けします。

## 2 ##
## リセットスイッチ、TRRS コネクタの取付け ##
白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてから半田付けするとミスが少なくなります。  

TRRS コネクタを図のように実装します。また、その下にあるジャンパー2箇所に半田を盛って導通するようにします。  
<img width="700" alt="ResetSW" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rpp_rev02_LED_TRRS_RESETsw_soldering.jpg">  

## 3 ##
## Raspberry Pi Pico の取付け ##
### Firmwareの書き込み ###
Raspberry Pi Pico に chromatoneminipico のファームウェアを書き込みます。  
Raspberry Pi Pico の BOOTSEL ボタンを押しながらUSBケーブルで PC/Mac と接続します。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPico.jpg">
<img width="700" alt="diode" src="/https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPicoWithUSBcable.jpg">

すると、Raspberry Pi Pico を USB ドライブとして認識します。  
もし USB ドライブとして認識しない場合は、USB ケーブルが充電専用のものではなく、ちゃんとデータ通信が可能なケーブルかどうかご確認ください。
（充電器に付属のケーブルなどは、データ通信線が無いものが多いですのでご注意ください。）  

[chromatonemini_led.uf2](https://github.com/3araht/chromatoneminipico/blob/main/chromatonemini_led.uf2) を Raspberry Pi Pico のドライブにドラッグ＆ドロップします。


## 4 ##
## Backlight RGB LEDの取付け[Optional] ##
イメージトレーニングが重要なので、まずは ”SK6812mini-E はんだ付け” で半田付けの様子を紹介している動画をチェックしてみてください。  
また、以下を使うことが成功の鍵となります。  
- 温度調整機能付き半田ごてで温度を240℃程度に設定する（白光 FX-600 の場合、270℃の1つ低い温度）。
- 融点の低い 鉛入り半田（共晶半田）を使う

こちらの[SK6812mini-E 半田付け事例](https://youtu.be/zy0iFEmkFuE?t=607) も参考にしていただけたら幸いです。

バックライト用のチップ LED(SK6812mini-E) は PCB の裏面から実装します。向きに注意して穴に入れてください。  

LEDはデータを直列に伝送する都合上、以下に示す順番にLEDを実装していき、都度動作確認をします。    
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/LED_serial.jpg">
偶数行と奇数行のLEDの向きが違うので十分ご注意ください。  

半田付けが軌道に乗った矢先に向きを間違えがちです。
その時のショックと言ったら。。。（経験者談）。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/SK6812mini_alignment.jpg">

温調半田ごてを使い、約240℃で半田付けします。温度が高いとLEDが壊れますので注意してください。
温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。

下図の位置を半田でジャンパします。  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/LED_jumper_r01.jpg">

LEDの情報は直列に伝送されますので、接続が途切れてしまうと正しくLEDが光らなくなります。

<img width="700" alt="Jumper" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rev02_LED_TRRS_RESETsw.jpg">  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/r02_LED_SK6812miniAndSK6812mini-E.jpg">  

SK6812mini-E は三角のマークの部分に切り欠きの入った端子（GND）が来るように実装します。  
三角マークはLEDの識別番号と重なってしまっていますが。。。  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/r02_LED_SK6812mini-E_1.jpg">  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/r02_LED_SK6812mini-E_2.jpg">  


## 5 ##
## 基板へのスペーサーのネジ止め ##
スペーサーを基板の裏面にネジで25箇所固定します（ネジをオモテ面に挿し、スペーサーが裏面にくるようにします）。  
キースイッチを半田付けした後にはネジを挿入することが難しい箇所があるため、キースイッチを半田付けする前に基板にネジを固定します。  
ただし、半田ごてがスペーサーに触れてしまうとスペーサーが溶けてしまうので、半田付けする際には十分ご注意ください。  
<img width="700" alt="switch" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Spacer_r01.jpg">  
1箇所 ボトムプレート に穴が空いていて 基板に穴があいていない箇所があります。そこにはネジどめはしません。

## 6 ##
## キースイッチの取付けと、エンコーダの取付け ##
**スイッチを取り付ける前に部品の取付けや半田付けができているか確認します。**  
（1 のダイオードは必ず済ませておいてください。）  

**動作確認する際には、①uf2ファイル書き込み済の Raspberry Pi Pico を実装し、②USBケーブルをPro Micro に挿して実施してください。**  
<img width="700" alt="switch" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Keysw_test.jpg">

キースイッチをオモテ側からしっかり奥まで差し込みます。このとき、端子が曲がっていると実装穴に端子が入らないので注意してください。1行ずつキースイッチをしっかり差し込んでから半田付けしていった方が差し込み不良は減らせると思います。  
<img width="700" alt="switch" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Keysw_rear_r01.jpg">

ロータリーエンコーダーを実装します。  
<img width="700" alt="RotaryEncorder" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rotary_encorder.jpg">

タクトスイッチも実装します。  
<img width="700" alt="TactSw" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/tact_sw.jpg">


## 7 ##
## 8 ##


### 8.1 ###

MIDIを使ったキーボードなのに、VIA 機能を有効にし、REMAP で動的にキー配列を変更できるようになりました！！！  

[REMAP](https://remap-keys.app/) でキー配列を自由に変更することが可能です。  

### 8.2 ###
### コーディングに慣れている方、チャレンジされる方 ###

暫定的に[こちら](https://github.com/3araht/chromatoneminipico/blob/main/temp/qmk_firmware/keyboards/chromatoneminipico)のソースコードをお使いください。

#### 8.2.1 ####
#### ソースの使い方 ####
1. まず、qmk_firmware を clone してきます。
https://github.com/qmk/qmk_firmware

3. 暫定的に UP している[こちら](https://github.com/3araht/chromatoneminipico/blob/main/temp/qmk_firmware/keyboards/chromatoneminipico)のソースコードを qmk_firmware/keyboards/chromatoneminipico に上書き保存します。

4. サスティン問題回避  
MIDIソフトによっては、同じ音を重ねて鳴らしたときにその音にUSBケーブルを抜き差しするまでサスティンがかかってしまう現象がありました。
~~対策方法がわかりましたので、それを適用します（こちらも pull request 中。正式に採用されるまでの暫定対策）。~~  
2020/10/5 pull request が メインブランチにマージされました。最新のソフトを clone いただければOKです。  
2021/04/13 残念ながら、2021/3/25 の process_midi.c の更新により、再びこの問題が復活しています。
コンパイル前に以下のコマンドでエンバグ前のコードを引っ張り出してコンパイルしてください。
```
git checkout c66df16 quantum/process_keycode/process_midi.c
```
### 8.3 ###
### 8.4 ###
#### layers ####
音符のレイアウト一覧  
<img width="700" alt="Layer" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/20210501_chromatoneminipico_notes_layout.png">    

エンコーダボタン長押ししたときの様子 Function(FN) Layer  
<img width="700" alt="Layer" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/20210502_chromatoneminipico_FN_layer.png">    


## 9 ##
## チェックポイント ##
簡単なチェック項目を挙げます。参考になれば幸いです。

【全体】
- Raspberry Pi Pico はしっかり基板に実装されている（裏面に実装した場合にはしっかり基板に刺さっている）。
- Raspberry Pi Pico のピンと基板のピンは一致させた状態で接続できている（Raspberry Pi Pico の上下の向き確認）。
- USB ケーブルは通信可能なものを使っている（充電器の付属品などは要注意）。
- Pro Micro にファームウェアを書き込んである。
- MIDI機器に対応したソフトを起動している。
- 半田付けに問題はないか（ダイオードの向き、赤目、富士山、など）。

以下、チェック項目です。
- テスター（マルチメータ）をお持ちの場合は、＋端子を5Vに、−端子をGND、またはその逆、 に当てて ダイオード測定してみてください。
  0.6 V 〜 2 V くらい表示されれば正常です。
- LEDの向きが正しいか(オモテ側からみて、小さな黒い点の向きが揃っているか。列ごとに向きが違うので注意)。
- 4つの端子が基板にしっかり半田付けできているか。数が多いので、数個半田が甘かった、ということはよくあります。
- あるところから先の LED が全く光らない場合は、その境界のLEDの信号線で半田不良 or LED 破損の可能性があります。
  LED の並びについては、上記 2 Backlight RGB LEDの取付け[Optional] をご覧ください。
- あるところから先の LED の光り方が変な場合は、その境界の LED の電源線（5V か GND）の半田不良 or LED 破損の可能性があります。
- LED は光るものの、他のLEDに比べて暗い場合は、その LED が半田ごてに熱でやられている可能性があります。R,G,Bのうち1つが光っていない、という壊れ方もあるようですので、色を変えて確認することをお勧めします。

また、遊舎工房さんの[サポートサイト](https://yushakobo.zendesk.com/hc/ja)が参考になると思います。併せてご覧ください。

## 10 ##
## ボトムプレートの組み立て ##
全てのキースイッチが正しく動作するのを確認したら、基板に取り付けたスペーサーにボトムプレートを固定します。
ボトムプレートの図の黄色丸の位置 26 箇所に M2 のねじでを挿入して固定します。  
<img width="700" alt="spacer" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/BottomPlate_r02_rpp.jpg">  

ネジ止めは、たすき掛けで均一に締めつけますが、強く締めつけすぎないようにします。

黄色丸の位置 15 箇所にクッションシールを取り付けます。  
<img width="700" alt="feet" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Cushon_r02.jpg">

#### お疲れ様でした。以上で chromatoneminipico キーボードの完成です！

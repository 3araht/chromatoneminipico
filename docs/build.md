# chromatoneminipico Build Guide
**一度すべて読んでから組み立てることをお勧めします。**

chromatonemini と chromatoneminipico の違い：

- chromatonemini は ProMicro、 chromatoneminipico は Raspberry Pi Pico を使います。
- chromatoneminipico は SK6812mini-E のみ対応
- chromatoneminipico は 111鍵の全てが独立しているので、KEYMAP などで独立したキー配列に変更することができます。<br>
  （一番上の2列＝19鍵＋18鍵＝37鍵 はその上のグリッサンド奏法用のキーとハードウェア的につながっています。）<br>

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
|PCかMac|1台|ファームウェアの書き込み、及び、キー配列の初期化（特にこちらで PCやMac版のChromeブラウザーが必要）にどうしても PC か Mac が必要になります（Linuxマシンでも行けると思いますが未確認）。特にキー配列の初期化で PCやMac版のChromeブラウザーが必要。|

### [Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|20 pin 2.5 mm コンスルー|2本|Raspberry Pi Pico を基板表面に直接実装する場合は不要です。|
|LED SK6812mini-E|116個|音階キー111個＋操作ボタン4個＋エンコーダ用1個。2の「Backlight RGB LED」を使う場合に必要。中級レベルの半田付けを伴うので、半田付け初心者の方は LED なしで組み立てられることをお勧め致します。|
|サスティンペダル|1台|ノーマリオフタイプ。念の為、極性変換スイッチつきのものをおすすめします。|
|3.5 mm ミニジャック変換ケーブル|1本|サスティンペダルのモノラルジャックを TRRS コネクタに刺さるように変換します。|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Raspberry Pi Pico、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

オモテ面<br>
<img width="700" alt="PCB" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/front_pcb_rpp_r02.jpg">

裏面<br>

基板の裏面には、ダイオードの実装場所やキーボード名が印字されています。<br>
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
ダイオードをつまんで両端の足を同時に曲げると図の右のように比較的ちょうどいい形になります。<br>
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_bend.jpg">

キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒い線のほうが四角いフットプリント（Kと印字されている方, K はKathode（独）の頭文字らしいですが、黒（Kuro) の K で。）に合うように配置します。<br>
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_align_rpp_r02.jpg">

足を曲げて基板に這わせてダイオードを仮止めします。<br>
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_flatten.jpg">

オモテ面から見た図<br>
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_flatten2_rpp_r02.jpg">

オモテ面から半田付けします。<br>
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_soldered_rpp_r02.jpg">

足をニッパでカットします（同上）。足は勢いよく飛んで行くので、足を押さえながら切ると良いです。<br>
<img width="700" alt="diode" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/diode_feet_cut_rpp_r02.jpg">

これをD1 〜 D117 の117箇所半田付けします。

## 2 ##
## リセットスイッチ、TRRS コネクタの取付け ##
白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてから半田付けするとミスが少なくなります。<br>

TRRS コネクタを図のように実装します。また、その下にあるジャンパー2箇所に半田を盛って導通するようにします。<br>
<img width="700" alt="ResetSW" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rpp_rev02_LED_TRRS_RESETsw_soldering.jpg"><br>

## 3 ##
## Raspberry Pi Pico の準備 ##
### 3.1 ###
### Firmwareの書き込み ###
Raspberry Pi Pico に chromatoneminipico のファームウェアを書き込みます。<br>

まず、
[chromatoneminipico_led.uf2](https://github.com/3araht/chromatoneminipico/blob/main/chromatoneminipico_led.uf2) を ダウンロードします。<br>

Raspberry Pi Pico の BOOTSEL ボタンを押しながらUSBケーブルで PC/Mac と接続します。<br>
このことで、ブードローダ状態（＝ファームウェアを書き込める状態）になります。
<img width="700" alt="Raspberry Pi Pico" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPico.jpg">
<img width="700" alt="Raspberry Pi Pico with USB cable" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPicoWithUSBcable.jpg">

すると、Raspberry Pi Pico を USB ドライブとして認識します。<br>
もし USB ドライブとして認識しない場合は、USB ケーブルが充電専用のものではなく、ちゃんとデータ通信が可能なケーブルかどうかご確認ください。
（充電器に付属のケーブルなどは、データ通信線が無いものが多いですのでご注意ください。）<br>

ダウンロードした chromatoneminipico_led.uf2 をRaspberry Pi Pico のドライブにドラッグ＆ドロップします。<br>
これで Raspberry Pi Pico の書き込みは終わりです。<br>
(Raspberry Pi Pico を初めて使われる方は、手始めに LED の点滅＝通称「Lチカ」を試されると良いかもしれません。)<br>

なお、一度このファームウェアを書き込むと、リセットボタンを素早く2回押すとブートローダ状態になるようになっているみたいです。なんて便利！(後述しますが、このファームウェア作成を可能にしてくださった せきごん さん様様です)。<br>

### 3.2 ###
### REMAP を使った初期キー配列の初期化 ###
[REMAP](https://remap-keys.app/) でキー配列を自由に変更することが可能です。<br>
ファームウェアを書き込んだ Raspberry Pi Pico をPC/Mac に接続した状態で Chrome ブラウザを使って上記リンクにアクセスしてください(残念ながら、iPhone、iPad、タブレットなどのブラウザでは非対応)。<br>
キー配列をデフォルトのままで使用する場合も、最初の1回は以下の手順でキー配列の初期化を行ってください。<br>

したの部分をクリック。<br>
<img width="700" alt="REMAP reset" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/chromatoneminipico_REMAP_reset1.png"><br>

"Reset Keymap" を選択。<br>
<img width="700" alt="REMAP reset" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/chromatoneminipico_REMAP_reset2.png"><br>

本当に初期化していいですか？と聞かれるので"Yes"します。<br>
<img width="700" alt="REMAP reset" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/chromatoneminipico_REMAP_reset3.png"><br>

完了すると、右上にその旨表示されます。これで、初期値のキー配列を使用できるようになります。<br>
<img width="700" alt="REMAP reset" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/chromatoneminipico_REMAP_reset4.png"><br>

#### このファームウェアでの REMAP の挙動について ####
原因不明ですが、 今回の Raspberry Pi Pico のファームウェアでは、REMAP 機能の1つである "Test Matrix mode" が動作しません。 ちゃんとキーを認識して音も出るのですが、"Test Matrix mode" でそのキーが押されたという判定になりませんでした。6, で示すように、キースイッチの動作確認は実際に音がでるかどうかで判断します。<br>


### Raspberry Pi Pico の取付け ###
chromatoneminipico は Raspberry Pi Pico を:
- 基板のオモテ面、裏面、どちらにも取り付けることができます。<br>
- オモテ面に実装する場合は、表面実装することもできるようになっています（コンスルーやピンヘッダが不要）。
- オモテ面、裏面に実装する場合、ピンヘッダも使えますが、コンスルーを使えば半田付けは不要です。

コンスルーをお使いの場合は、半田付け不要なので、オモテ面に実装した後に、気分が変わって後から裏面に隠すこともできます。<br>
コンスルーの入手性があまりよく無いため、コンスルーが無くても表面実装できるようになっています。<br>

基板のオモテ面にコンスルーで実装した場合。<br>
<img width="700" alt="Raspberry Pi Pico on top of the board" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPicoOnTopWithConthrough.jpg"><br>

基板の裏面にコンスルーで実装した場合(裏面から見た図)。<br>
<img width="700" alt="Raspberry Pi Pico below the board" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPicoBelowWithConthrough.jpg"><br>

基板の裏面にコンスルーで実装した場合（オモテ面からみた図。BOOTSELがピンセットなどで押せるようになっています）。<br>
<img width="700" alt="Raspberry Pi Pico below the board, top view" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPicoBelowWithConthroughTopView.jpg"><br>

基板のオモテ面に表面実装する場合。このビルドガイドでは、表面実装した例を紹介します。<br>
<img width="700" alt="Raspberry Pi Pico on top of the board, soldered" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/RaspberryPiPicoOnTop.jpg"><br>

ピンヘッダがある場合、位置決めに使うと便利です。<br>
<img width="700" alt="Raspberry Pi Pico on top of the board, soldered" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rpp_soldering1.jpg"><br>

最初に3箇所くらい半田付けをします。その後、位置決め用のピンヘッダは取り除きます。<br>
<img width="700" alt="Raspberry Pi Pico on top of the board, soldered" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rpp_soldering2.jpg"><br>

半田付けが完了した様子。<br>
<img width="700" alt="Raspberry Pi Pico on top of the board, soldered" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rpp_soldering3.jpg"><br>

半田付けが完了した様子（part2）。<br>
<img width="700" alt="Raspberry Pi Pico on top of the board, soldered" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rpp_soldering4.jpg"><br>


## 4 ##
## Backlight RGB LED の取付け[Optional] ##
**LED を実装されない方は "5, 基板へのスペーサーのネジ止め" へ進んでください**<br>
イメージトレーニングが重要なので、まずは ”SK6812mini-E はんだ付け” で半田付けの様子を紹介している動画をチェックしてみてください。<br>
また、以下を使うことが成功の鍵となります。<br>
- 温度調整機能付き半田ごてで温度を240℃程度に設定する（白光 FX-600 の場合、270℃の1つ低い温度、下図参照）。
- 融点の低い 鉛入り半田（共晶半田）を使う

半田ごての温度設定<br>
<img width="700" alt="SolderIronTemperature" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/FX-600A_240degC.jpg"><br>

こちらの[SK6812mini-E 半田付け事例](https://youtu.be/zy0iFEmkFuE?t=607) も参考にしていただけたら幸いです。

まず、下図の位置を半田でジャンパします。これにより、Raspberry Pi Pico から LED のデータ線に信号が送られるようになります。<br>
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/LED_jumper_rpp_r02.jpg"><br>

バックライト用のチップ LED(SK6812mini-E) は PCB の裏面から実装します。向きに注意して穴に入れてください。<br>

LED はデータを直列に伝送する都合上、以下に示す順番に LED を実装していき、都度動作確認をします。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/LED_serial_rpp_r02.jpg"><br>
SK6812mini-E は三角のマークの部分に切り欠きの入った端子（GND）が来るように実装します。<br>
偶数行と奇数行の LED の向きが違うので十分ご注意ください。<br>
半田付けが軌道に乗った矢先に向きを間違えがちです。
その時のショックと言ったら。。。（経験者談）。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/SK6812mini_alignment_rpp_r02.jpg"><br>

温調半田ごてを使い、約240℃で半田付けします。温度が高いと LED が壊れますので注意してください。
温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。<br>
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/SK6812mini_soldered_rpp_r02.jpg"><br>

LED の情報は直列に伝送されますので、接続が途切れてしまうと正しく LED が光らなくなります。<br>

LED の半田付けが終わったら、他のパーツの実装には270〜320℃が適切ですので、設定温度を戻しておきます。<br>


## 5 ##
## 基板へのスペーサーのネジ止め ##
スペーサーを基板の裏面にネジで25箇所固定します（ネジをオモテ面に挿し、スペーサーが裏面にくるようにします）。<br>
キースイッチを半田付けした後にはネジを挿入することが難しい箇所があるため、キースイッチを半田付けする前に基板にネジを固定します。<br>
ただし、半田ごてがスペーサーに触れてしまうとスペーサーが溶けてしまうので、半田付けする際には十分ご注意ください。<br>
<img width="700" alt="switch" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rear_pcb_spacers_rpp_r02.jpg"><br>
1箇所 ボトムプレート に穴が空いていて 基板に穴があいていない箇所があります。そこにはネジどめはしません。

## 6 ##
## キースイッチの取付けと、エンコーダの取付け ##
**スイッチを取り付ける前に部品の取付けや半田付けができているか確認します。**<br>
（1 のダイオードは必ず済ませておいてください。）<br>

**動作確認する際には、①uf2ファイル書き込み済の Raspberry Pi Pico を実装し、②USBケーブルをPro Micro に挿して実施してください。**<br>
<img width="700" alt="switch" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Keysw_test_rpp_r02.jpg">

キースイッチをオモテ側からしっかり奥まで差し込みます。このとき、端子が曲がっていると実装穴に端子が入らないので注意してください。1行ずつキースイッチをしっかり差し込んでから半田付けしていった方が差し込み不良は減らせると思います。<br>
また、一度に2つの端子を同時に半田付けするのでは無く、1つの端子を半田付けするときに、しっかり奥まで刺さっていることを確認した後で2つ目の端子を半田付けすると間違い無いです。<br>
<img width="700" alt="switch" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Keysw_rear_rpp_r02.jpg">

ロータリーエンコーダーを実装します。<br>
<img width="700" alt="RotaryEncorder" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/rotary_encorder_rpp_r02.jpg">

タクトスイッチも実装します。<br>
<img width="700" alt="TactSw" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/tact_sw_rpp_r02.jpg">


## 7 キーキャップ 取り付け ##
キーキャップをキースイッチに取り付けて行きます。キーキャップによっては、上下逆には刺さっても、左右方向を90度回転させて上下方向にすると刺さらないものもありますので、とても固い場合は、90度回転していないか確認してみてください。<br>
<img width="700" alt="TactSw" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/keycaps_rpp_r02.jpg">


## 8 ##
## チェックポイント ##
簡単なチェック項目を挙げます。参考になれば幸いです。

【全体】
- Raspberry Pi Pico はしっかり基板に実装されている（裏面に実装した場合にはしっかり基板に刺さっている）。
- Raspberry Pi Pico のピンと基板のピンは一致させた状態で接続できている（Raspberry Pi Pico の上下の向き確認）。
- USB ケーブルは通信可能なものを使っている（充電器の付属品などは要注意）。
- Raspberry Pi Pico にファームウェアを書き込んである。また、REMAP を使った初期キー配列の初期化が済んでいる。
- MIDI機器に対応したソフトを起動している。
- 半田付けに問題はないか（ダイオードの向き、赤目、富士山、など）。

【Backlight RGB LED編】<br>
- テスター（マルチメータ）をお持ちの場合は、＋端子を5Vに、−端子をGND、またはその逆、 に当てて ダイオード測定してみてください。
  0.6 V 〜 2 V くらい表示されれば正常です。
- LED の向きが正しいか(オモテ側からみて、小さな黒い点の向きが揃っているか。列ごとに向きが違うので注意)。
- 4つの端子が基板にしっかり半田付けできているか。数が多いので、数個半田が甘かった、ということはよくあります。
- あるところから先の LED が全く光らない場合は、その境界の LED の信号線で半田不良 or LED 破損の可能性があります。
  LED の並びについては、上記 2 Backlight RGB LED の取付け[Optional] をご覧ください。
- あるところから先の LED の光り方が変な場合は、その境界の LED の電源線（5V か GND）の半田不良 or LED 破損の可能性があります。
- LED は光るものの、他の LED に比べて暗い場合は、その LED が半田ごてに熱でやられている可能性があります。R,G,Bのうち1つが光っていない、という壊れ方もあるようですので、色を変えて確認することをお勧めします。

また、遊舎工房さんの[サポートサイト](https://yushakobo.zendesk.com/hc/ja)が参考になると思います。併せてご覧ください。

## 9 ##
## ボトムプレートの組み立て ##
全てのキースイッチが正しく動作するのを確認したら、基板に取り付けたスペーサーにボトムプレートを固定します。
ボトムプレートの図の黄色丸の位置 25 箇所に M2 のねじでを挿入して固定します。<br>
1箇所ボトムプレートに穴があって基板の方に穴がない部分があります( x 印の箇所)。ここはねじ止めしません。<br>
<img width="700" alt="spacer" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/BottomPlate_r02_rpp.jpg"><br>

ネジ止めは、たすき掛けで均一に締めつけますが、強く締めつけすぎないようにします。

黄色丸の位置 15 箇所にクッションシールを取り付けます。<br>
<img width="700" alt="feet" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/Cushon_rpp_r02.jpg">

#### お疲れ様でした。以上で chromatoneminipico キーボードの完成です！



## 10 ##
## 付録 ##
### 10.1 ###
### コーディングされる場合の手順 ###

#### 10.1.1 ####
#### コーディングされる場合の環境準備 ####
※2023/9/23 現在、qmk 0.22.2 で動作確認しています。

まず qmk firmware を clone します。 clone の詳しい方法などは私よりも詳しい方が説明されている別のサイトを参考にしてください。

次に、chromatoneminipico のソースコードを以下のリンクからダウンロードして、 `qmk_firmware/keyboards` フォルダに chromatoneminipico フォルダごと貼り付けます。<br>
[こちら](https://github.com/3araht/chromatoneminipico/blob/main/temp/qmk_firmware/keyboards/chromatoneminipico)のソースコードをお使いください。<br>

サスティン問題回避<br>
MIDIソフトによっては、同じ音を重ねて鳴らしたときにその音にUSBケーブルを抜き差しするまでサスティンがかかってしまう現象がありました。
~~対策方法がわかりましたので、それを適用します（こちらも pull request 中。正式に採用されるまでの暫定対策）。
2020/10/5 pull request が メインブランチにマージされました。最新のソフトを clone いただければOKです。~~<br>
2021/04/13 残念ながら、2021/3/25 の `process_midi.c` の更新により、再びこの問題が復活しています。<br>
2023/09/23 以下の Pull Request から下記ファイルを取得し、`process_midi.c` を差し替えてください。

https://github.com/qmk/qmk_firmware/pull/22114
https://github.com/qmk/qmk_firmware/blob/e8906ed2ea0b9f20291b2759d4d65fc6c334ab39/quantum/process_keycode/process_midi.c

```
quantum/process_keycode/process_midi.c
```

ちなみに上記 Pull Request は Reject されることが予想されます。`process_midi.c` は別の方の使用目的と conflict しているようです。

#### 10.1.2 ####
#### カスタマイズ ####
キーマップの変更など、自由にカスタマイズしてください。

#### 10.1.3 ####
#### コンパイル ####
qmk_firmware のフォルダで以下のコマンドを実行すると、
```
$ make chromatoneminipico:led
```

Raspberry Pi Pico をブートローダ状態にしたときにドラッグ＆ドロップでファームウェアを書き込める uf2 ファイルが出来上がるはずです。<br>
（この例では、led というキーマップのファームをコンパイルした例になります。）<br>

なお、ファームウェアの書き込みですが、以下のコマンドを実装するときに Raspberry Pi Pico をブートローダ状態にしておくと、自動で uf2 ファイルを Raspberry Pi Pico に書き込んでくれました。<br>
```
$ make chromatoneminipico:led:flash
(実行後、長いコンパイルの後、)
Flashing for bootloader: rp2040
Flashing /Volumes/RPI-RP2 (RPI-RP2)
Wrote 113664 bytes to /Volumes/RPI-RP2/NEW.UF2
```

#### 10.1.4 ####
#### 初期キー配列の初期化 ####
ファームウェアを書き込んだ後は、[REMAP を使った初期キー配列の初期化](#32) を参考にしてキー配列を初期化してください。<br>

### 10.2 ###
#### layers ####
音符のレイアウト一覧<br>
2021/12/28 追記: Erwan Mellec さんからアコーディオンの左手側の配列も追加してほしいというご要望頂きまして、ACCORDIONBASS レイヤーを追加しました。<br>
Erwan さん、ご要望いただきありがとうございました！！！<br>


<img width="700" alt="Layer" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/20220807_chromatoneminipico_notes_layout.png"><br>

エンコーダボタン長押ししたときの様子 Function(FN) Layer<br>
<img width="700" alt="Layer" src="https://github.com/3araht/chromatoneminipico/blob/main/pictures/20220807_chromatoneminipico_FN_layer.png"><br>

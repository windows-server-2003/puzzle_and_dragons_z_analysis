エミュレータ(citra)と自動操作(AutoHotkey)で得られた初期盤面サンプルのデータです。  
$2$ 台のPCを使ったため、`pc0`と`pc1`にディレクトリを分けていますが、合わせたデータも`combined.txt`にあります。  
各ファイルは、 $1$ 行が $1$ 盤面に対応しており、 $1$ つの行は長さ $30$ の数字列と改行からなります。  
この $30$ 個の数字は順に、盤面の**上の行**から、同じ行の中では左から順に見た $30$ 個のドロップのそれぞれの種類を表す整数です。  
火, 水, 木, 光, 闇, 回復がこの順に $0$ ~ $5$ に対応します。(ただしこのデータではステージが火水木回復の $4$ 種類ダンジョンなため $0, 1, 2, 5$ しか出現しません)

採取ステージ :  
	シャングリラエリア 妖精の森ステージ $3$ 妖精の宮殿  

採取サンプル数 :  

 - pc0 : $20423$  
 - pc1 : $28895$  
 - combined : $49318$  

//
// PlanDetailPage.xaml.cpp
// PlanDetailPage クラスの実装
//

#include "pch.h"
#include "PlanDetailPage.xaml.h"
#include "Windows.UI.Xaml.Controls.h"
#include "Windows.UI.Xaml.Media.Imaging.h"
#include "Windows.Foundation.h"
#include "HomePage.xaml.h"

using namespace Group4_project;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Foundation;


// 空白ページの項目テンプレートについては、https://go.microsoft.com/fwlink/?LinkId=234238 を参照してください

int currentPage = 1;

PlanDetailPage::PlanDetailPage()
{
	InitializeComponent();
	UpdatePage();
}

void PlanDetailPage::HomePage_click(Object^ sender, RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(HomePage::typeid));
}

void PlanDetailPage::ShowImage1_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/kiyomizudera.jpg"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/syurizyou.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/tokeidai.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/mayumaro.png"));
		break;
	}

	SpotImage1->Source = image;
}

void PlanDetailPage::ShowImage2_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/kinkakuji.gif"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/suizokukann.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/unnga.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/negi-man.png"));
		break;
	}


	SpotImage2->Source = image;
}


void PlanDetailPage::ShowImage3_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/fushimiinari.gif"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/kouritou.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/hana.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/zinkun.jpg"));
		break;
	}

	SpotImage3->Source = image;
}


void PlanDetailPage::ShowImage4_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/yatsuhashi.png"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/so-kisoba.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/zingisukann.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/meronkuma.jpg"));
		break;
	}

	SpotImage4->Source = image;
}


void PlanDetailPage::ShowImage5_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/yudouhu.jpg"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/go-yatyanpuru.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/ra-menn.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/ryuutyan.jpg"));
		break;
	}

	SpotImage5->Source = image;
}


void PlanDetailPage::ShowImage6_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/mattay.jpg"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/takoraisu.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/susi.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/kamenn.jpg"));
		break;
	}

	SpotImage6->Source = image;
}


void PlanDetailPage::ShowImage7_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/kimono.jpg"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/syamisenn.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/suki-.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/fot.png"));
		break;
	}

	SpotImage7->Source = image;
}


void PlanDetailPage::ShowImage8_Click(Object^ sender, RoutedEventArgs^ e)
{
	BitmapImage^ image = nullptr;

	switch (currentPage)
	{
	case 1:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/kyouto/tyadou.jpg"));

		break;
	case 2:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/okinawa/syuno-keringu.jpg"));
		break;
	case 3:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/hokkaidou/usi.jpg"));
		break;

	case 4:
		image = ref new BitmapImage(ref new Uri("ms-appx:///Assets/yurukyara/ber.png"));
		break;
	}

	SpotImage8->Source = image;
}

void PlanDetailPage::PrevPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (currentPage > 1)
	{
		currentPage--;
		UpdatePage();

		// ダミーボタンにフォーカスを移動
		DummyFocusButton->Focus(Windows::UI::Xaml::FocusState::Programmatic);
		// ScrollViewer のスクロール位置を設定
		MainScrollViewer->ScrollToVerticalOffset(0.0);
		MainScrollViewer->ScrollToHorizontalOffset(0.0);



	}
}

void PlanDetailPage::NextPage_Click(Object^ sender, RoutedEventArgs^ e)
{
	if (currentPage < 4)
	{
		currentPage++;
		UpdatePage();

		// ダミーボタンにフォーカスを移動
		DummyFocusButton->Focus(Windows::UI::Xaml::FocusState::Programmatic);
		// ScrollViewer のスクロール位置を設定
		MainScrollViewer->ScrollToVerticalOffset(0.0);
		MainScrollViewer->ScrollToHorizontalOffset(0.0);


	}
}



void PlanDetailPage::UpdatePage()
{
	// 画像を消す処理
	SpotImage1->Source = nullptr; // 画像1を消す
	SpotImage2->Source = nullptr; // 画像2を消す
	SpotImage3->Source = nullptr; // 画像3を消す
	SpotImage4->Source = nullptr; // 画像4を消す
	SpotImage5->Source = nullptr; // 画像5を消す
	SpotImage6->Source = nullptr; // 画像6を消す
	SpotImage7->Source = nullptr; // 画像7を消す
	SpotImage8->Source = nullptr; // 画像8を消す

	switch (currentPage)
	{
	case 1:
		AreaTitle->Text = "京都";
		PageLabel->Text = "1 京都";
		SpotTitle1->Text = "清水寺";
		SpotComment1_Line1->Text = "音羽山の中腹に位置する清水寺は、豊かな自然に囲まれ\n四季折々の美しい景色を楽しめる名所です。\n\n";

		SpotTitle2->Text = "金閣寺";
		SpotComment1_Line2->Text = "金箔で覆われた豪華な寺院で\nその美しい姿は世界中から訪れる観光客を魅力します。\n\n";

		SpotTitle3->Text = "伏見稲荷";
		SpotComment1_Line3->Text = "朱色の鳥居が連なる神秘的な場所で\n圧倒的なスケールの中で精神的なパワーを感じることができます。\n\n";

		SpotTitle4->Text = "八つ橋";
		SpotComment1_Line4->Text = "京都の伝統的な和菓子で、シナモン風味が特徴。\nお土産としても人気で、香り豊かな味わいが魅力です。\n\n";

		SpotTitle5->Text = "湯豆腐";
		SpotComment1_Line5->Text = "京都の豆腐料理で、精進料理の一つとしても有名。\n柔らかくてまろやかな味わいが特徴です。\n\n";

		SpotTitle6->Text = "抹茶";
		SpotComment1_Line6->Text = "宇治を中心に親しまれる抹茶は、アイスやスイーツでも人気。\n香り豊かな味わいを楽しめます。\n\n";

		SpotTitle7->Text = "着物体験";
		SpotComment1_Line7->Text = "歴史的な街並みを背景に、伝統的な和装を体験。\n美しい着物姿で町を歩くのは、京都ならではの特別な経験です。\n\n";

		SpotTitle8->Text = "茶道";
		SpotComment1_Line8->Text = "日本の伝統文化である茶道を学べる教室が各地に点在。\n心を落ち着け、和の精神を感じる貴重な体験です。\n\n";

		break;

	case 2:
		AreaTitle->Text = "沖縄";
		PageLabel->Text = "2 沖縄";
		SpotTitle1->Text = "首里城";
		SpotComment1_Line1->Text = "沖縄の歴史を象徴する世界遺産で、赤い屋根が印象的な首里城。\n沖縄王国の栄華を感じさせる建築美です。\n\n";

		SpotTitle2->Text = "美ら海水族館";
		SpotComment1_Line2->Text = "ジンベエザメやマンタが泳ぐ巨大な水槽。\n沖縄の海の生物を間近で観察でき、海の世界を体験できます。\n\n";

		SpotTitle3->Text = "古宇利島";
		SpotComment1_Line3->Text = "透き通る海と白い砂浜が広がる、沖縄の隠れた楽園。\nドライブや海水浴が楽しめるリラックススポットです。\n\n";

		SpotTitle4->Text = "ソーキそば";
		SpotComment1_Line4->Text = "沖縄名物の麺料理でコシのある麺と豚肉の旨味が\n絶妙に絡み合った、風味豊かな一杯です。\n\n";

		SpotTitle5->Text = "ゴーヤチャンプル";
		SpotComment1_Line5->Text = "ゴーヤのほろ苦さと豚肉の旨味が特徴の沖縄定番の炒め物料理。\n健康にも良いと評判です。\n\n";

		SpotTitle6->Text = "タコライス";
		SpotComment1_Line6->Text = "ご飯の上にタコスの具材をのせた沖縄発祥の創作料理。\nボリューム満点で食べ応えがあります。\n\n";

		SpotTitle7->Text = "三味線体験";
		SpotComment1_Line7->Text = "沖縄の伝統楽器、三味線を実際に弾いてみることができます。\n音楽の魅力を感じながら、沖縄の文化に触れる体験です。\n\n";

		SpotTitle8->Text = "シュノーケリング";
		SpotComment1_Line8->Text = "サンゴ礁と熱帯魚が豊富な沖縄の海でシュノーケリングを楽しめます。\n色とりどりの魚たちと泳ぐ贅沢な時間です。\n\n";

		break;

	case 3:
		AreaTitle->Text = "北海道";
		PageLabel->Text = "3 北海道";
		SpotTitle1->Text = "札幌時計台";
		SpotComment1_Line1->Text = "北海道のシンボルとも言える歴史的建造物。\n札幌市の中心に位置し、街の風景と調和した美しい建物です。\n\n";

		SpotTitle2->Text = "小樽運河";
		SpotComment1_Line2->Text = "石造りの倉庫群が並び、ノスタルジックな雰囲気が漂う小樽運河。\n夕暮れ時の風景が特にロマンチックです。\n\n";

		SpotTitle3->Text = "富良野";
		SpotComment1_Line3->Text = "ラベンダー畑や広大な自然が広がる富良野。\n四季折々の景色が楽しめ、特に夏のラベンダーは絶景です。\n\n";

		SpotTitle4->Text = "ジンギスカン";
		SpotComment1_Line4->Text = "羊肉を使用した北海道の名物料理。\n甘辛ダレで焼くスタイルが特徴で、香ばしい味わいが絶妙です。\n\n";

		SpotTitle5->Text = "ラーメン";
		SpotComment1_Line5->Text = "北海道のラーメンは、特に味噌ラーメンが有名。\n濃厚でコクのあるスープと、もちもちの麺が絶品です。\n\n";

		SpotTitle6->Text = "海鮮丼";
		SpotComment1_Line6->Text = "新鮮なウニやイクラを贅沢に盛りつけた海鮮丼。\n海道の海の幸を贅沢に味わえる一杯です。\n\n";

		SpotTitle7->Text = "スキー・スノボー";
		SpotComment1_Line7->Text = "ニセコや富良野など、世界的に有名なスキー場があります。\n雪質が良く、スノボーやスキー愛好者に最適な場所です。\n\n";

		SpotTitle8->Text = "牧場体験";
		SpotComment1_Line8->Text = "牛の乳しぼりやアイスクリーム作りができる牧場体験。\n北海道ならではの自然を感じながら、農業体験を楽しめます。\n\n";

		break;
	case 4:
		AreaTitle->Text = "ご当地キャラ特集";
		PageLabel->Text = "4 ゆるキャラ";
		SpotTitle1->Text = "まゆまろ（京都）";
		SpotComment1_Line1->Text = "京都府の広報監。まゆ玉の形をした平安装束キャラ。\nほっこり笑顔が人気で、全国ゆるキャラグランプリ常連！\n\n";
		SpotTitle2->Text = "ネギーまん（京都・九条ねぎ）";
		SpotComment1_Line2->Text = "九条ねぎをモチーフにした京都のローカルヒーロー。\n頭がネギ！野菜のパワーで悪を倒す！？\n\n";
		SpotTitle3->Text = "ジンくん（北海道）";
		SpotComment1_Line3->Text = "ジンギスカンの妖精キャラ。鉄鍋帽子と羊スタイルが特徴。\n優しい性格で、北海道グルメをPR中！\n\n";
		SpotTitle4->Text = "メロン熊（北海道・夕張）";
		SpotComment1_Line4->Text = "夕張メロンと熊が合体！？\nちょっと怖い顔だけど、イベントでは大人気！\n\n";
		SpotTitle5->Text = "りゅうちゃん（沖縄）";
		SpotComment1_Line5->Text = "沖縄県警の安全マスコット。\n龍をモチーフにした子どもに人気の頼れるキャラ！\n\n";
		SpotTitle6->Text = "ウラソエ仮面（沖縄）";
		SpotComment1_Line6->Text = "浦添市のヒーローキャラ。\n交通安全や地域イベントで活躍中！\n\n";
		SpotTitle7->Text = "キャラと記念写真！";
		SpotComment1_Line7->Text = "イベントや観光地で出会えたらぜひ記念撮影を。\nかわいい姿と思い出を一緒に残そう！\n\n";
		SpotTitle8->Text = "あなたの推しは？";
		SpotComment1_Line8->Text = "お気に入りのキャラは見つかった？\n旅のお土産にグッズもおすすめ！\n\n";
		break;
	}
}


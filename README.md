まず、フォルダ構造を簡単に紹介し、次に「LoginPage」の機能、最後にCSVファイルを使ったデータ接続について説明します。では、始めましょう！

１．	イメージ
  1.1 　MainPage:

 ![image](https://github.com/user-attachments/assets/6fb80629-0ca9-4960-be7e-b9da4ff517ca)

  1.2  LoginPage:

 ![image](https://github.com/user-attachments/assets/09dbe674-dd9d-4ed9-a868-17876f0958be)


  1.3 RegisterPage: 

 ![image](https://github.com/user-attachments/assets/6fa15ba6-fb6f-4783-b20a-06d69d6233a4)


２． フォルダ構造について
プロジェクトのフォルダはこんな感じです：

![image](https://github.com/user-attachments/assets/02c5d7e3-5713-4614-9f8f-1dc7351f01e4)

- ReferencesとExternal Dependencies: 外部ライブラリや依存関係。
- Assets: 画像やアイコンなどのリソース。
- Common: 共通のコードやユーティリティ。
- Data:
  ・ `UserDataHelper.cpp`と`UserDataHelper.h`: ユーザー管理のヘルパー関数。
  ・　`users.csv`: ユーザー情報を保存するCSVファイル。
- App.xaml, HomePage.xaml, LoginPage.xaml, MainPage.xaml, RegisterPage.xaml: 各ページのUIとロジック（`.xaml`, `.xaml.cpp`, `.xaml.h`）。
・`package.appxmanifest`: アプリの設定ファイル。
・ `pch.cpp`と`pch.h`: プリコンパイル済みヘッダー。

この構造で、ログイン、登録、ホーム画面などが管理されています。

3. LoginPageの機能について
 3.1   LoginPage.xaml：
 

ログイン画面のデザインです：
- TextBlock: 「ログイン」タイトル。
- TextBox: メール入力欄。
- PasswordBox: パスワード入力欄。
- Button: 「ログイン」ボタン（`LoginButton_Click`で動作）。
- HyperlinkButton: 登録ページへのリンク（`GoToRegisterPage_Click`）。
- もう一つのButton: メイン画面に戻る「戻る」ボタン（`GoBackToMainPage_Click`）。



 3.2  LoginPage.xaml.cpp
ログインの動作を制御します：
- コンストラクタ: `InitializeComponent()`でXAMLを画面に反映。
- LoginButton_Click:
  - メールとパスワードを取得。
  - `UserDataHelper::LoadUsers()`でデータを読み込み、照合。
  - 一致すれば`HomePage`へ、失敗なら「ログイン失敗」ダイアログを表示。
- GoBackToMainPage_Click: メイン画面に移動。
- GoToRegisterPage_Click: 登録ページに移動。


 3.3  LoginPage.xaml.h
クラスの宣言：
- `LoginPage`クラスを定義し、3つのイベント関数を準備。

4. CSVファイルのデータ接続について
4.1  UserDataHelper.h
- User構造体: `email`、`password`、`name`を格納。
- UserDataHelperクラス: `LoadUsers()`と`SaveUser()`を定義。

 4.2  UserDataHelper.cpp
- LoadUsers関数:
  - `LocalFolder`から`users.csv`を読み込み、なければ`Assets`から初期データ。
  - カンマで区切ったデータを`User`構造体に変換し、`std::vector`に追加。
- SaveUser関数:
  - `LocalFolder`に新しいデータを追加書き込み。
  - 成功なら`true`、失敗なら`false`。

 4.3  users.csv
- 形式: `email,password,name`。
- 例: `user1@example.com,123456,User One`など。
- `LoadUsers`で読み込み、`SaveUser`で更新。



まとめ
プロジェクトはフォルダ構造で整理され、`LoginPage`でログイン機能を実現し、`UserDataHelper`でCSVからデータを読み書きします。質問があれば、遠慮なくどうぞ！

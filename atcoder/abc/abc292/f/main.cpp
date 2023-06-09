#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



// グラフを表すデータ構造

using Graph = vector<vector<int>>;



int main() {

	// 入力

	int N, M;

	cin >> N >> M;

	Graph G(N);

	for (int i = 0; i < M; ++i) {

		int A, B;

		cin >> A >> B;



		// 頂点 A から頂点 B への辺を張る

		G[A].push_back(B);

		G[B].push_back(A);

	}

    

    // 各頂点が何手目に探索されたか

    // -1 は「まだ探索されていない」ことを表す

    vector<int> dist(N, -1);



    // k 手目に探索された頂点集合を格納 (最大でも N-1 手まで)

    vector<vector<int>> nodes(N);



    // 頂点 0 を始点とする

    dist[0] = 0;

    nodes[0] = {0};



    // k 手目の探索をする

    for (int k = 1; k < N; ++k) {

        // k-1 手目に探索された各頂点 v に対して

        for (auto v : nodes[k - 1]) {

            // 頂点 v から 1 手で行ける頂点 next_v を探索

            for (auto next_v : G[v]) {

                // 頂点 next_v が探索済みであれば何もしない

                if (dist[next_v] != -1) {

                    continue;

                }



                // 頂点 next_v を探索する

                dist[next_v] = dist[v] + 1;

                nodes[k].push_back(next_v);

            }

        }

    }

}
#include <vector>

class Solution {
	public:

	  int ans = -1;
	int max = -1;
	int maxVol;

	void go(int volume, int size, std::vector < int > value) {
	  // 종료조건
	  if (volume > maxVol || volume < 0) return;

	  if (size == value.size() - 1) {
		volume += value[size];
		if (volume > maxVol) {
		  volume -= 2 * value[size];
		  if (volume < 0) return;
		}
		if (volume > max) {
		  max = volume;
		  ans = max;
		}
		return;
	  }

	  go(volume + value[size], size + 1, value);
	  go(volume - value[size], size + 1, value);

	}

	int solution(std::vector < int > volumes, int beginVolume, int maxVolume) {
	  maxVol = maxVolume;

	  go(beginVolume, 0, volumes);

	  return ans;
	}
};
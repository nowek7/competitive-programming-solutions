#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes)
{
    std::vector<std::vector<int>> groups;

    std::unordered_map<int, std::vector<int>> store;
    for (int i = 0; i < groupSizes.size(); ++i) {
        store[groupSizes.at(i)].push_back(i);
    }

    for (auto& [groupSize, people]: store) {
        if (groupSize < people.size()) {
            for (int i = 0; i < people.size(); i += groupSize) {
                std::vector<int> group;
                for (int k = 0; k < groupSize; ++k) {
                    group.push_back(people[i + k]);
                }
                groups.push_back(group);
            }
        } else {
            groups.push_back(people);
        }
    }

    return groups;
}

void print(std::vector<std::vector<int>>&& groups) {
    for (auto group: groups) {
        if (!group.empty()) {
            std::cout << "GROUP" << '\n';
            for (int i = 0; i < group.size() - 1; ++i) {
                std::cout << group.at(i) << " ";
            }
            std::cout << *group.rbegin() << '\n';
        }
    }
}

int main()
{
    // 1282. Group the People Given the Group Size They Belong To
    {
        std::vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
        print(groupThePeople(groupSizes));
    }

    {
        std::vector<int> groupSizes = {2, 1, 3, 3, 3, 2};
        print(groupThePeople(groupSizes));
    }

    return 0;
}
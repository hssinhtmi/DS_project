#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <regex>

class Node
{
public:
    char galaxyName;
    char nodeName;
    int id;

    Node(char _galaxyName, char _nodeName, int _id) : galaxyName(_galaxyName), nodeName(_nodeName), id(_id) {}
};

class Galaxy
{
public:
    char name;
    std::vector<Node> nodes;

    Galaxy(char _name) : name(_name) {}

    void addNode(char nodeName, int nodeId)
    {
        nodes.emplace_back(name, nodeName, nodeId);
    }
};

class World
{
public:
    std::vector<Galaxy> galaxies;
    std::map<int, std::vector<std::pair<int, double>>> connections;

    void addGalaxy(char galaxyName)
    {
        galaxies.emplace_back(galaxyName);
    }

    void connectNodes(int node1Id, int node2Id, double weight)
    {
        connections[node1Id].emplace_back(node2Id, weight);
        connections[node2Id].emplace_back(node1Id, weight);
    }

    std::pair<double, std::vector<int>> shortestPath(int startNodeId, int endNodeId)
    {
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq;
        std::map<int, double> distance;
        std::map<int, int> previous;

        for (const auto &galaxy : galaxies)
        {
            for (const auto &node : galaxy.nodes)
            {
                distance[node.id] = std::numeric_limits<double>::max();
            }
        }
        distance[startNodeId] = 0.0;
        pq.push({0.0, startNodeId});

        while (!pq.empty())
        {
            double dist = pq.top().first;
            int current = pq.top().second;
            pq.pop();

            if (dist > distance[current])
            {
                continue;
            }

            for (const auto &neighbor : connections[current])
            {
                double newDist = dist + neighbor.second;
                if (newDist < distance[neighbor.first])
                {
                    distance[neighbor.first] = newDist;
                    previous[neighbor.first] = current;
                    pq.push({newDist, neighbor.first});
                }
            }
        }

        double shortestWeight = distance[endNodeId];
        std::vector<int> path;
        int currentNode = endNodeId;
        while (currentNode != startNodeId)
        {
            path.insert(path.begin(), currentNode);
            currentNode = previous[currentNode];
        }
        path.insert(path.begin(), startNodeId);

        return {shortestWeight, path};
    }

    int show_id(char galaxy_name, char node_name)
    {
        for (const Galaxy &galaxy : galaxies)
        {
            if (galaxy.name == galaxy_name)
            {
                for (const Node &node : galaxy.nodes)
                {
                    if (node.nodeName == node_name)
                    {
                        return node.id;
                    }
                }
            }
        }
        return -1;
    }
    int letter_find(std::string text)
    {
        char galaxy_name;
        char node_name;
        size_t dotPosition = text.find('.');

        if (dotPosition != std::string::npos && dotPosition > 0 && dotPosition < text.length() - 1)
        {
            galaxy_name = text[dotPosition - 1];
            node_name = text[dotPosition + 1];
        }
        return show_id(galaxy_name, node_name);
    }

    void displayGalaxiesAndNodes()
    {
        for (const Galaxy &galaxy : galaxies)
        {
            std::cout << "Galaxy " << galaxy.name << ":\n";
            for (const Node &node : galaxy.nodes)
            {
                std::cout << "  Node " << node.galaxyName << "." << node.nodeName << " (ID: " << node.id << ")\n";
            }
            std::cout << "\n";
        }
    }
};

char show_letter(std::string text)
{
    std::smatch match;
    std::regex createRegex(R"RE(CREATE \((\w))RE");
    std::regex idRegex(R"RE(id: '(\d+)')RE");

    std::regex_search(text, match, createRegex);
    return match[1].str()[0];
}

int show_number(std::string text)
{
    std::smatch match;
    std::regex createRegex(R"RE(CREATE \((\w))RE");
    std::regex idRegex(R"RE(id: '(\d+)')RE");

    std::regex_search(text, match, idRegex);
    return stoi(match[1]);
}

std::vector<double> show_3_number(std::string text)
{
    std::vector<double> temp_3_number;

    std::regex numberRegex("\\d+\\.?\\d*|\\d*\\.\\d+");
    std::smatch matches;

    std::istringstream iss(text);
    std::string word;

    while (iss >> word)
    {
        if (std::regex_search(word, matches, numberRegex))
        {
            temp_3_number.push_back(std::stod(matches[0]));
        }
    }
    return temp_3_number;
}

int main()
{
    World world;
    
    world.addGalaxy('a');
    world.addGalaxy('b');
    world.addGalaxy('c');

    std::vector<double> temp_3_number;

    std::string text = "CREATE (a: Node, {id: '0', Type: 'BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (b: Node, {id: '1', Type: 'NON-BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (c: Node, {id: '2', Type: 'BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (d: Node, {id: '3', Type: 'BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (e: Node, {id: '4', Type: 'NON-BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (f: Node, {id: '5', Type: 'NON-BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (g: Node, {id: '6', Type: 'NON-BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (h: Node, {id: '7', Type: 'NON-BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (i: Node, {id: '8', Type: 'BG'})";
    world.galaxies[0].addNode(show_letter(text), show_number(text));

    text = "CREATE (j: Node, {id: '9', Type: 'BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (k: Node, {id: '10', Type: 'BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (l: Node, {id: '11', Type: 'BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (m: Node, {id: '12', Type: 'NON-BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (n: Node, {id: '13', Type: 'NON-BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (o: Node, {id: '14', Type: 'NON-BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (p: Node, {id: '15', Type: 'NON-BG'})";
    world.galaxies[1].addNode(show_letter(text), show_number(text));

    text = "CREATE (q: Node, {id: '16', Type: 'NON-BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (r: Node, {id: '17', Type: 'BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (s: Node, {id: '18', Type: 'BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (t: Node, {id: '19', Type: 'BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (u: Node, {id: '20', Type: 'NON-BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (v: Node, {id: '21', Type: 'NON-BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (w: Node, {id: '22', Type: 'NON-BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (x: Node, {id: '23', Type: 'NON-BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (y: Node, {id: '24', Type: 'NON-BG'})";
    world.galaxies[2].addNode(show_letter(text), show_number(text));

    text = "CREATE (0) - [:ROAD {cost:0.2}] -> (3)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (3) - [:ROAD {cost:1.3}] -> (9)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (8) - [:ROAD {cost:0.6}] -> (11)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (10) - [:ROAD {cost:2}] -> (17)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (18) - [:ROAD {cost:0.8}] -> (19)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (3) - [:ROAD {cost:0.8}] -> (11)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (0) - [:ROAD {cost:0.5}] -> (1)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (2) - [:ROAD {cost:7}] -> (7)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (4) - [:ROAD {cost:3}] -> (8)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (1) - [:ROAD {cost:1.6}] -> (5)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (12) - [:ROAD {cost:1.2}] -> (13)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (10) - [:ROAD {cost:3}] -> (14)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (10) - [:ROAD {cost:1}] -> (15)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (10) - [:ROAD {cost:50}] -> (20)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (16) - [:ROAD {cost:2}] -> (17)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (20) - [:ROAD {cost:0.95}] -> (21)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (22) - [:ROAD {cost:0.5}] -> (24)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);
    text = "CREATE (18) - [:ROAD {cost:3.5}] -> (23)";
    temp_3_number = show_3_number(text);
    world.connectNodes(temp_3_number[0], temp_3_number[2], temp_3_number[1]);

    text = "FIND a.a->a.a";
    size_t findPos = text.find("FIND");
    size_t arrowPos = text.find("->");
    std::string textAfterFind;
    std::string textAfterArrow;

    if (findPos != std::string::npos && arrowPos != std::string::npos)
    {
        textAfterFind = text.substr(findPos + 4, arrowPos - (findPos + 4));
        textAfterArrow = text.substr(arrowPos + 2);
    }
    int node_1_id_hold = world.letter_find(textAfterFind);

    int node_2_id_hold = world.letter_find(textAfterArrow);

    auto result = world.shortestPath(node_1_id_hold, node_2_id_hold);
    double shortestWeight = result.first;
    std::vector<int> path = result.second;

    for (int nodeId : path)
    {
        for (const Galaxy &galaxy : world.galaxies)
        {
            for (const Node &node : galaxy.nodes)
            {
                if (node.id == nodeId)
                {
                    std::cout << node.galaxyName << "." << node.nodeName << "->";
                    break;
                }
            }
        }
    }

    std::cout << " " << shortestWeight << std::endl;

    return 0;
}

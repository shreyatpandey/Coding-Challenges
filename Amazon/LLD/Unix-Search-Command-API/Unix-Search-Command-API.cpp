#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <memory>
#include <sstream>

// File
class File {
    private:
        std::string name;
        long long size;
        bool is_directory;
        std::vector<std::shared_ptr<File>> children;
        std::string extension;
    
    public:
        File(std::string name, long long size) : name(std::move(name)), size(size) {
            if (this->name.find('.') == std::string::npos) {
                this->is_directory = true;
            } else {
                this->is_directory = false;
                size_t dot_pos = this->name.find('.');
                if (dot_pos != std::string::npos && dot_pos + 1 < this->name.length()) {
                    this->extension = this->name.substr(dot_pos + 1);
                }
            }
        }
    
        const std::string& getName() const {
            return name;
        }
    
        long long getSize() const {
            return size;
        }
    
        bool isDirectory() const {
            return is_directory;
        }
    
        const std::vector<std::shared_ptr<File>>& getChildren() const {
            return children;
        }
    
        void addChild(const std::shared_ptr<File>& child) {
            children.push_back(child);
        }
    
        const std::string& getExtension() const {
            return extension;
        }
    
        std::string toString() const {
            return "{" + name + "}";
        }
    };
    

// Filters
class Filter {
public:
    virtual ~Filter() = default;
    virtual bool apply(const File& file) const = 0;
};

class MinSizeFilter : public Filter {
private:
    long long size;

public:
    MinSizeFilter(long long size) : size(size) {}
    bool apply(const File& file) const override {
        return file.getSize() > this->size;
    }
};

class ExtensionFilter : public Filter {
private:
    std::string extension;

public:
    ExtensionFilter(std::string extension) : extension(std::move(extension)) {}
    bool apply(const File& file) const override {
        return file.getExtension() == this->extension;
    }
};

// LinuxFindCommand
class LinuxFind {
private:
    std::vector<std::unique_ptr<Filter>> filters;

public:
    void addFilter(std::unique_ptr<Filter> filter) {
        if (filter) {
            filters.push_back(std::move(filter));
        }
    }

    std::vector<std::shared_ptr<File>> applyORFiltering(const std::shared_ptr<File>& root) const {
        std::vector<std::shared_ptr<File>> found_files;
        std::deque<std::shared_ptr<File>> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            std::shared_ptr<File> current_root = queue.front();
            queue.pop_front();

            if (current_root->isDirectory()) {
                for (const auto& child : current_root->getChildren()) {
                    queue.push_back(child);
                }
            } else {
                for (const auto& filter : filters) {
                    if (filter->apply(*current_root)) {
                        found_files.push_back(current_root);
                        std::cout << current_root->toString() << std::endl;
                        break;
                    }
                }
            }
        }
        return found_files;
    }

    std::vector<std::shared_ptr<File>> applyANDFiltering(const std::shared_ptr<File>& root) const {
        std::vector<std::shared_ptr<File>> found_files;
        std::deque<std::shared_ptr<File>> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            std::shared_ptr<File> current_root = queue.front();
            queue.pop_front();

            if (current_root->isDirectory()) {
                for (const auto& child : current_root->getChildren()) {
                    queue.push_back(child);
                }
            } else {
                bool is_valid = true;
                for (const auto& filter : filters) {
                    if (!filter->apply(*current_root)) {
                        is_valid = false;
                        break;
                    }
                }
                if (is_valid) {
                    found_files.push_back(current_root);
                    std::cout << current_root->toString() << std::endl;
                }
            }
        }
        return found_files;
    }
};

int main() {
    auto f1 = std::make_shared<File>("root_300", 300);

    auto f2 = std::make_shared<File>("fiction_100", 100);
    auto f3 = std::make_shared<File>("action_100", 100);
    auto f4 = std::make_shared<File>("comedy_100", 100);
    f1->addChild(f2);
    f1->addChild(f3);
    f1->addChild(f4);

    auto f5 = std::make_shared<File>("StarTrek_4.txt", 4);
    auto f6 = std::make_shared<File>("StarWars_10.xml", 10);
    auto f7 = std::make_shared<File>("JusticeLeague_15.txt", 15);
    auto f8 = std::make_shared<File>("Spock_1.jpg", 1);
    f2->addChild(f5);
    f2->addChild(f6);
    f2->addChild(f7);
    f2->addChild(f8);

    auto f9 = std::make_shared<File>("IronMan_9.txt", 9);
    auto f10 = std::make_shared<File>("MissionImpossible_10.rar", 10);
    auto f11_action = std::make_shared<File>("TheLordOfRings_3.zip", 3);
    f3->addChild(f9);
    f3->addChild(f10);
    f3->addChild(f11_action);

    auto f11_comedy = std::make_shared<File>("BigBangTheory_4.txt", 4);
    auto f12 = std::make_shared<File>("AmericanPie_6.mp3", 6);
    f4->addChild(f11_comedy);
    f4->addChild(f12);

    auto greater5_filter = std::make_unique<MinSizeFilter>(5);
    auto txt_filter = std::make_unique<ExtensionFilter>("txt");

    LinuxFind my_linux_find;
    my_linux_find.addFilter(std::move(greater5_filter));
    my_linux_find.addFilter(std::move(txt_filter));

    std::cout << "OR Filtering Results:" << std::endl;
    auto or_results = my_linux_find.applyORFiltering(f1);
    std::cout << "Found (OR): ";
    for (const auto& file : or_results) {
        std::cout << file->toString() << " ";
    }
    std::cout << std::endl;

    std::cout << "\nAND Filtering Results:" << std::endl;
    auto and_results = my_linux_find.applyANDFiltering(f1);
    std::cout << "Found (AND): ";
    for (const auto& file : and_results) {
        std::cout << file->toString() << " ";
    }
    std::cout << std::endl;

    return 0;
}
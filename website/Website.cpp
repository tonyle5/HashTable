#include "Website.h"

// Constructor with parameters
Website::Website(const char* topic, const char* address, const char* summary,
                 const char* review, unsigned short int rating) {
  setCharArr(topic, this->topic);
  setCharArr(address, this->address);
  setCharArr(summary, this->summary);
  setCharArr(review, this->review);
  this->rating = rating;
}

/**
 * Copy constructor.
 *
 * @param other The website object to be copied.
 */
Website::Website(const Website& other) {
  *this = other;
}

/**
 * Copy assignment operator.
 *
 * @param other The website object to be assigned.
 * @return Reference to the updated website object.
 */
Website& Website::operator=(const Website& other) {
  if (this != &other) {
    this->init(other.topic, other.address, other.summary, other.review,
               other.rating);
  }

  return *this;
}

/**
 * This function prints the data using a particular output stream.
 *
 * @param os The output stream.
 * @return void
 */
void Website::printInformation(ostream& os) {
  os << this->getTopic() << ";";
  os << this->getAddress() << ";";
  os << this->getSummary() << ";";
  os << this->getReview() << ";";
  os << this->getRating() << ";";
}

/**
 * Destructor.
 */
Website::~Website() {
  freeDynamicArray<char>(this->topic);
  freeDynamicArray<char>(this->address);
  freeDynamicArray<char>(this->summary);
  freeDynamicArray<char>(this->review);
}

// Getters
const char* Website::getTopic() const {
  return this->topic;
}

const char* Website::getAddress() const {
  return this->address;
}

const char* Website::getSummary() const {
  return this->summary;
}

const char* Website::getReview() const {
  return this->review;
}

unsigned short int Website::getRating() const {
  return this->rating;
}

// Setters
void Website::setTopic(const char* topic) {
  setCharArr(topic, this->topic);
}

void Website::setAddress(const char* address) {
  setCharArr(address, this->address);
}

void Website::setSummary(const char* summary) {
  setCharArr(summary, this->summary);
}

void Website::setReview(const char* review) {
  setCharArr(review, this->review);
}

void Website::setRating(unsigned short int rating) {
  this->rating = rating;
}

// Initializes the website's properties.
void Website::init(const char* topic = nullptr, const char* address = nullptr,
                   const char* summary = nullptr,
                   const char* review = nullptr,
                   unsigned short int rating = 0) {
  this->setTopic(topic);
  this->setAddress(address);
  this->setSummary(summary);
  this->setReview(review);
  this->setRating(rating);
}
